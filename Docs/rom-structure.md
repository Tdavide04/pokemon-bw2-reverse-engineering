# ROM Structure – Technical Notes

> **Scope**
> These notes describe the internal structure of *Pokémon White 2* (Nintendo DS, Generation 5) at a **technical and organizational level**.
> The focus is on how the game stores and organizes data (maps, scripts, events, assets), not on distributing copyrighted content.
> Intended for **educational purposes and ROM hacking research**.

---

## 1. ROM Overview

* **Platform:** Nintendo DS
* **ROM size:** ~256 MB
* **File format:** `.nds`
* **Primary CPUs:** ARM9 + ARM7
* **Compression:** LZ77 (widely used for graphics, scripts, and data tables)

### ROM Partitions

A Nintendo DS ROM is divided into several logical sections:

* **ROM Header**

  * Game title and ID
  * Region and version info
  * Checksums
  * ARM9 / ARM7 entry points

* **ARM9 Binary**

  * Core game logic
  * Battle engine
  * Map engine
  * Event handling

* **ARM7 Binary**

  * Audio processing
  * Wireless and low-level I/O
  * Support routines

* **File System (FAT + FNT)**

  * Virtual file system mapping
  * Data archives and resources

---

## 2. Nintendo DS File System (FAT / FNT)

Pokémon White 2 uses the standard Nintendo DS **Nitro File System (NitroFS)**.

### FAT – File Allocation Table

* Maps each file to:

  * Start offset in ROM
  * File size
* Used by the engine to locate data quickly

### FNT – File Name Table

* Stores directory hierarchy
* Associates file IDs with human-readable paths

Together, FAT and FNT allow the ROM to behave like a structured filesystem rather than a monolithic binary.

---

## 3. High-Level Directory Layout

The ROM filesystem is organized into numbered directories, each grouping a category of data.

Common top-level directories include:

* `a/0/` – Core data tables
* `a/1/` – Maps, events, and scripts
* `a/2/` – Graphics and UI assets
* `a/3/` – Audio-related data
* `a/4/` – Pokémon-related data

> Directory numbering is a convention used by Game Freak and varies slightly between titles.

---

## 4. Map and World Data

Maps are composed of multiple components stored separately:

* **Map geometry and layout**
* **Tile graphics and palettes**
* **Collision data**
* **Event and script triggers**

These elements are combined at runtime by the map engine.

### Typical Map Components

* **Tilesets** (NCGR / NCLR / NSCR)
* **Map matrix** (how maps connect)
* **Event files** (NPCs, warps, triggers)
* **Scripts** (cutscenes, dialogue, logic)

---

## 5. Scripts and Events

Scripts control:

* NPC dialogue
* Story progression
* Cutscenes
* Conditional logic based on flags and variables

### Script Characteristics

* Stored as compiled binary scripts
* Interpreted by the game’s script engine
* Heavily dependent on:

  * **Flags** (boolean state)
  * **Variables** (numeric state)

Script execution is central to progression control.

---

## 6. Flags and Variables

### Flags

* Boolean values (on / off)
* Used for:

  * Story progression
  * One-time events
  * Feature unlocking

### Variables

* Numeric values
* Used for:

  * Counters
  * Player choices
  * Conditional branching

Flags and variables are globally accessible to scripts and engine logic.

---

## 7. Pokémon Data

Pokémon-related data is split into multiple tables:

* Species base stats
* Learnsets
* Evolutions
* Abilities
* Forms

Each table is indexed by **species ID**, allowing fast lookups at runtime.

---

## 8. Trainers and Battles

Trainer data includes:

* Trainer class
* Party composition
* AI parameters
* Rewards

Battle behavior is defined by:

* Core battle engine (ARM9)
* Trainer AI scripts
* Move and ability data

---

## 9. Graphics and UI Assets

Graphics are tile-based and include:

* Sprites (NPCs, Pokémon, UI)
* Backgrounds
* Menus
* Overlays

Common formats:

* **NCGR** – Tile graphics
* **NCLR** – Color palettes
* **NCER / NSCR** – Tile and cell layouts

Assets are often reused across multiple contexts.

---

## 10. Overlays

Overlays are dynamically loaded ARM9 code segments used to:

* Reduce memory usage
* Load context-specific logic (menus, battles, cutscenes)

Characteristics:

* Loaded and unloaded at runtime
* Share memory regions
* Must be handled carefully when debugging or injecting code

---

## 11. Runtime Assembly

At runtime, the engine:

1. Loads binaries and overlays
2. Decompresses required assets
3. Resolves pointers and indices
4. Executes scripts and logic

The final game state is the result of **multiple independent systems interacting**.

---

## 12. Summary

* Pokémon White 2 uses a modular, filesystem-driven ROM layout
* Data is separated by category and loaded on demand
* Maps, scripts, and graphics are independent but tightly coordinated
* Understanding structure is essential before making modifications

> Effective ROM hacking starts with understanding *where* data lives before changing *how* it behaves.

---

## Legal Notice

This document is intended for educational and research purposes.
No proprietary game assets, binaries, or copyrighted material
are included or distributed.

All trademarks belong to their respective owners.

