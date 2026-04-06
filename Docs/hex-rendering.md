# HEX-Level Image Rendering Manipulation – Technical Notes

> **Scope**
> These notes describe, at a low level, how HEX editing affects image rendering in Nintendo DS–era engines (e.g. Pokémon Black 2 / White 2). The focus is on understanding how binary data is interpreted by the rendering pipeline, not on distributing copyrighted assets.

---

### Tools Used

* **Tinke** — Used as a binary inspection and debugging tool to analyze
  Nintendo DS resource containers (NCGR, NCER, NCLR).
  It was helpful for understanding tile layouts, tilemaps, and rendering behavior.

---

## 1. Rendering Pipeline Overview

At runtime, images are not rendered directly from "image files" but reconstructed from multiple binary resources:

1. **Graphics / Tileset** – raw pixel data (e.g. NCGR)
2. **Palette** – color definitions (e.g. NCLR)
3. **Tilemap / Cellmap** – layout instructions (e.g. NSCR, NCER)
4. **Engine Logic** – code that interprets the above structures

When editing HEX, you are modifying **data consumed by the engine**, not high-level images.

---

## 2. Hexadecimal Notation

In hexadecimal, values are counted from `0` to `F` instead of `0` to `9`:

```
Decimal:  0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16
Hex:      0  1  2  3  4  5  6  7  8  9   A   B   C   D   E   F  10
```

Values in a hex editor appear as byte pairs such as `00`, `0A`, `4F`, `7C`, `FF`.
`FF` represents decimal 255.

---

## 3. Tiles: The Fundamental Unit

### 3.1 Tile Properties

* Size: **8×8 pixels**
* Color depth:

  * 4bpp → 16 colors per tile
  * 8bpp → 256 colors per tile
* Stored sequentially in memory

Each tile has an **implicit index** derived from its position in the file:

```
Tile 00, Tile 01, Tile 02, ... Tile N
```

Tiles are ordered left-to-right, top-to-bottom starting from `00`.
There are **no pointers** between tiles.

---

## 4. Graphics Files (e.g. NCGR)

### 4.1 Structure

Typical NCGR layout:

* Header (magic, version, size)
* Tile data block

Tile data is stored as raw pixel values:

* Each byte (or nibble) represents a color index
* The palette is resolved separately

### 4.2 HEX Editing Effects

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

## 5. Tilemaps / Cellmaps (e.g. NSCR, NCER)

### 5.1 Purpose

Tilemaps do **not contain graphics**.
They describe **which tile index** is drawn at a given screen position.

To edit a screen layout (e.g. a title logo), the tilemap file must be opened
in Tinke or a hex editor and modified manually until each screen position
references the correct tile from the associated graphics file.

### 5.2 BW2 Logo Location

In Pokémon Black 2 / White 2, the title screen logo is located at:

```
a/0/2/6
```

This archive contains three files related to the logo:

* `6_0` — the **Tileset** (source graphics, raw tile pixel data)
* `6_1` — the **Tilemap** (layout instructions, maps screen positions to tile indices)
* `6_2` — the **Palette** (colors)

### 5.3 Entry Structure (Typical)

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
```
4F 00
```

Little-endian interpretation:
```
0x004F → decimal 79
```

Result: the renderer draws **tile #79** from the associated graphics file at this screen position.

---

### 5.4 Tile Index Range and Two-Byte Counting

Tile indices are stored as **2-byte little-endian** values and are not limited to `FF` (255).
The second byte acts as a page counter:

```
First page  (second byte = 00):   00 00  →  tile #0
                                  01 00  →  tile #1
                                  ...
                                  FF 00  →  tile #255

Second page (second byte = 01):   00 01  →  tile #256
                                  01 01  →  tile #257
                                  ...
                                  FF 01  →  tile #511

Third page  (second byte = 02):   00 02  →  tile #512
                                  ...
```

When the first byte reaches `FF`, the second byte increments and the first resets to `00`.
Images with more than 256 tiles will require values beyond `FF 00`.

---

### 5.5 Why Screens Turn Black

A black screen typically means:

* Tile index points to **empty / zeroed tile**
* Palette index is invalid
* Tile index exceeds available tiles

Notably:

> **Zero is a valid tile index** and often maps to a fully transparent or black tile.

---

## 6. No Pointers: Indices vs Addresses

A critical concept:

* **Tilemaps use indices, not memory pointers**

This means:

* `0x0001` → "Use tile #1"
* NOT → "Jump to memory address 0x0001"

Changing a value:

```
01 00 → 20 00
```

Does **not redirect memory**, it simply selects **tile #32**.

---

## 7. Endianness Considerations

Nintendo DS uses **little-endian** encoding.

Example:

```
01 02
```

Interpreted as:

```
0x0201
```

When editing tile indices, always reverse bytes logically.

---

## 8. Palette Interaction

### 8.1 Palette Files (NCLR)

* Contain RGB555 values
* Index 0 is often transparent

### 8.2 Common Rendering Issues

| Symptom         | Cause                        |
| --------------- | ---------------------------- |
| All black       | Palette missing / wrong slot |
| Wrong colors    | Palette mismatch             |
| Invisible image | All pixels use color 0       |

HEX edits in graphics without matching palette updates often cause visual corruption.

---

## 9. Alignment and Boundaries

Tile data must respect strict boundaries:

* 1 tile = fixed number of bytes
* Misalignment causes desynchronization

For 4bpp:

```
8×8 pixels = 32 bytes per tile
```

Shifting data by even **1 byte** will corrupt all subsequent tiles.

---

## 10. Engine-Level Constraints

Even if HEX data is valid, rendering can fail due to:

* Hardcoded tile limits
* Expected tile counts
* Fixed VRAM allocation

Thus:

> Correct HEX does not guarantee correct rendering.

---

## 11. Debugging Strategy

Recommended workflow:

1. Identify file role (graphics / map / palette)
2. Confirm tile count and color depth
3. Edit **one value at a time**
4. Test on **Tinke**
5. Compare with known-good files

---

## 12. Summary

* HEX edits modify **data**, not images
* In hexadecimal, values go from `0` to `F`; `FF` equals decimal 255
* Every 8×8 pixel block is a tile, indexed from `00` left-to-right, top-to-bottom
* In BW2, the title logo is at `a/0/2/6`: `6_0` is the tileset, `6_1` is the tilemap
* Tilemap entries are 2-byte little-endian indices; beyond `FF 00` the second byte increments
* Tilemaps reference tiles by **index**, not pointer
* Black screens usually indicate invalid indices or palettes
* Understanding structure is mandatory before editing

> Rendering is deterministic: if you understand the binary format, the result is predictable.

## Legal Notice

This document is intended for educational and research purposes.
No proprietary game assets, binaries, or copyrighted material
are included or distributed.

All trademarks belong to their respective owners.
