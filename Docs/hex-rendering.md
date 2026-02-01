# HEX-Level Image Rendering Manipulation – Technical Notes

> **Scope**
> These notes describe, at a low level, how HEX editing affects image rendering in Nintendo DS–era engines (e.g. Pokémon Black 2 / White 2). The focus is on understanding how binary data is interpreted by the rendering pipeline, not on distributing copyrighted assets.

---

### Tools Used

- **Tinke** — Used as a binary inspection and debugging tool to analyze
  Nintendo DS resource containers (NCGR, NCER, NCLR).
  It was helpful for understanding tile layouts, tilemaps, and rendering behavior.

---

## 1. Rendering Pipeline Overview

At runtime, images are not rendered directly from "image files" but reconstructed from multiple binary resources:

1. **Graphics (Tiles)** – raw pixel data (e.g. NCGR)
2. **Palette** – color definitions (e.g. NCLR)
3. **Tilemap / Cellmap** – layout instructions (e.g. NSCR, NCER)
4. **Engine Logic** – code that interprets the above structures

When editing HEX, you are modifying **data consumed by the engine**, not high-level images.

---

## 2. Tiles: The Fundamental Unit

### 2.1 Tile Properties

* Size: **8×8 pixels**
* Color depth:

  * 4bpp → 16 colors per tile
  * 8bpp → 256 colors per tile
* Stored sequentially in memory

Each tile has an **implicit index**:

```
Tile 0, Tile 1, Tile 2, ... Tile N
```

There are **no pointers** between tiles; the index is derived from position in the file.

---

## 3. Graphics Files (e.g. NCGR)

### 3.1 Structure

Typical NCGR layout:

* Header (magic, version, size)
* Tile data block

Tile data is stored as raw pixel values:

* Each byte (or nibble) represents a color index
* The palette is resolved separately

### 3.2 HEX Editing Effects

Editing HEX in a graphics file:

* Changes **pixel color indices**
* Does **not** move tiles
* Does **not** affect layout

Common effects:

| HEX Change              | Visual Effect           |
| ----------------------- | ----------------------- |
| Modify nibble           | Pixel color changes     |
| Shift bytes             | Corrupted tile graphics |
| Overwrite tile boundary | Tile distortion         |

---

## 4. Tilemaps / Cellmaps (e.g. NSCR, NCER)

### 4.1 Purpose

Tilemaps do **not contain graphics**.
They describe **which tile index** is drawn at a given screen position.

### 4.2 Entry Structure (Typical)

A tilemap entry is usually **16 bits**:

```
BBBB TTTT TTTT TTTT
```

Where:

* `TTTT TTTT TTTT` → Tile index (0–4095)
* `B` bits → Attributes (engine-specific)

---

#### Example: Tile Index Resolution

Tilemap entry (hex):
4F 00

Little-endian interpretation:
0x004F → decimal 79

Result:

The renderer draws **tile #79** from the associated graphics file
at this screen position.

---

Common attribute bits:

| Bit      | Meaning             |
| -------- | ------------------- |
| Flip H   | Horizontal flip     |
| Flip V   | Vertical flip       |
| Palette  | Palette slot (4bpp) |
| Priority | Draw order          |

### 4.3 Why Screens Turn Black

A black screen typically means:

* Tile index points to **empty / zeroed tile**
* Palette index is invalid
* Tile index exceeds available tiles

Notably:

> **Zero is a valid tile index** and often maps to a fully transparent or black tile.

---

## 5. No Pointers: Indices vs Addresses

A critical concept:

* **Tilemaps use indices, not memory pointers**

This means:

* `0x0001` → "Use tile #1"
* NOT → "Jump to memory address 0x0001"

Changing a value:

```hex
01 00 → 20 00
```

Does **not redirect memory**, it simply selects **tile #32**.

---

## 6. Endianness Considerations

Nintendo DS uses **little-endian** encoding.

Example:

```hex
01 02
```

Interpreted as:

```
0x0201
```

When editing tile indices, always reverse bytes logically.

---

## 7. Palette Interaction

### 7.1 Palette Files (NCLR)

* Contain RGB555 values
* Index 0 is often transparent

### 7.2 Common Rendering Issues

| Symptom         | Cause                        |
| --------------- | ---------------------------- |
| All black       | Palette missing / wrong slot |
| Wrong colors    | Palette mismatch             |
| Invisible image | All pixels use color 0       |

HEX edits in graphics without matching palette updates often cause visual corruption.

---

## 8. Alignment and Boundaries

Tile data must respect strict boundaries:

* 1 tile = fixed number of bytes
* Misalignment causes desynchronization

For 4bpp:

```
8×8 pixels = 32 bytes per tile
```

Shifting data by even **1 byte** will corrupt all subsequent tiles.

---

## 9. Engine-Level Constraints

Even if HEX data is valid, rendering can fail due to:

* Hardcoded tile limits
* Expected tile counts
* Fixed VRAM allocation

Thus:

> Correct HEX does not guarantee correct rendering.

---

## 10. Debugging Strategy

Recommended workflow:

1. Identify file role (graphics / map / palette)
2. Confirm tile count and color depth
3. Edit **one value at a time**
4. Test on **Tinke**
5. Compare with known-good files

---

## 12. Summary

* HEX edits modify **data**, not images
* Tilemaps reference tiles by **index**, not pointer
* Black screens usually indicate invalid indices or palettes
* Understanding structure is mandatory before editing

> Rendering is deterministic: if you understand the binary format, the result is predictable.

## Legal Notice

This document is intended for educational and research purposes.
No proprietary game assets, binaries, or copyrighted material
are included or distributed.

All trademarks belong to their respective owners.


