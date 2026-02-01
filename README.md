# Pokémon White 2 – Technical Documentation

This repository contains **technical documentation and research notes** related to reverse engineering and ROM hacking of *Pokémon White 2* (Nintendo DS, Generation 5).

The project focuses on **understanding internal systems**, **debugging workflows**, and **documenting gameplay modifications**, rather than distributing game assets or binaries.

---

## Project Goals

* Document the **internal structure** of a Nintendo DS Pokémon ROM
* Explain **symbol-based debugging** using IDA Pro
* Describe **HEX-level rendering manipulation** and tile-based graphics
* Provide technical notes on **BeaterScript** and event scripting
* Track **gameplay changes and patches** in a structured way

This repository is intended as:

* educational material
* reverse-engineering research notes
* a technical reference for ROM hacking workflows

---

## Repository Structure

```text
/docs
 ├─ rom-structure.md        # ROM layout and data organization
 ├─ esdb-notes.md           # External Symbol Database (ESDB) notes
 ├─ ida-debugging.md        # In-game debugging with IDA Pro
 ├─ hex-rendering.md        # HEX-level rendering manipulation
 ├─ beaterscript.md         # BeaterScript scripting system notes
 └─ modifications.md        # Gameplay modifications and patches
```

Each document is self-contained and written to be GitHub-safe and tool-agnostic where possible.

---

## Documentation Overview

* **ROM Technical Structure**
  Overview of how Pokémon White 2 organizes binaries, data archives, maps, scripts, and assets.

* **ESDB – External Symbol Database**
  Explains how symbol metadata enables safer and more maintainable code injection.

* **In-Game Debugging with IDA Pro**
  Describes attaching IDA to a running game via an emulator GDB stub to trace execution in real time.

* **HEX-Level Rendering Manipulation**
  Covers tilemaps, palettes, and how HEX edits affect final rendering.

* **BeaterScript Technical Notes**
  Documents the scripting layer used for events, NPC behavior, and game logic.

* **Gameplay Modifications**
  Lists evolution changes, quality-of-life patches, and new features added to the game.

---

## Scope and Limitations

* This repository **does not include** ROMs, binaries, assets, or proprietary data
* No original game code is redistributed
* Instructions focus on **analysis and understanding**, not asset extraction

The content is intentionally limited to documentation and research notes.

---

## Legal Disclaimer

This repository is intended for **educational and research purposes only**.

No proprietary game assets, binaries, or copyrighted material are included or distributed.

All trademarks and copyrighted materials belong to their respective owners.

---

## Credits

This project builds upon tools, documentation, and shared knowledge from the
Pokémon reverse-engineering and ROM hacking community.

Special thanks to:

- **Hello007** — for the development of **CTRMap** and the Generation V code injection system  
- **PlatinumMaster** — for contributions and technical insights related to the Generation V code injection system  
- **totally_anonymous** — for documentation and research related to IDB generation and analysis

Their work and shared knowledge were instrumental in understanding and 
documenting the systems described in this repository.

## License

Unless otherwise stated, the documentation in this repository is released under the **Creative Commons Attribution 4.0 International (CC BY 4.0)** license.

You are free to:

* Share and adapt the material
* Use it for educational or research purposes

Provided that appropriate credit is given.


## Legal Notice

This document is intended for educational and research purposes.
No proprietary game assets, binaries, or copyrighted material
are included or distributed.

All trademarks belong to their respective owners.
