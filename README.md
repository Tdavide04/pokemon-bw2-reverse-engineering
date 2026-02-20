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
.
├─ Docs/
│   ├─ rom-structure.md        # Data organization and ROM layout
│   ├─ esdb-notes.md           # ESDB (External Symbol Database) basics
│   ├─ ida-debugging.md        # In-game debugging with IDA Pro
│   ├─ hex-rendering.md        # HEX-level rendering manipulation
│   ├─ beaterscript.md         # BeaterScript scripting system
│   └─ modifications.md       # Gameplay changes and patch overviews
├─ ESDBs/
│   ├─ Battle.yml
│   ├─ Field.yml
│   ├─ LvlCap.yml
│   └─ PokeList.yml
├─ PW2Code/
│   ├─ ExternalDependencies/   # Toolchain submodules (e.g., swan)
│   ├─ Headers/                # Code headers used for analysis
│   ├─ Patches/                # Applied patch source code
│   └─ idSet_Calcolator.py     # Utility scripts
├─ .gitignore
├─ LICENSE
└─ README.md
```

Each document is self-contained and written to be GitHub-safe and tool-agnostic where possible.

---

## Technical Areas Covered

* **ROM Structure** — How the Pokémon White 2 DS ROM organizes files, maps, and data archives.
* **ESDB** — How symbol databases help with code injection and debugging tools.
* **In-Game Debugging** — Attaching IDA Pro via an emulator GDB stub to observe runtime behavior.
* **HEX Rendering Manipulation** — How tilemaps and palette data produce final rendered screens.
* **BeaterScript Notes** — High-level scripting for in-game event logic and triggers.
* **Gameplay Modifications** — Descriptions of evolution changes, QoL patches, and gameplay tweaks.

---

** Toolchain Notes

**Swan Submodule
This project uses *swan* (a Git submodule) for toolchain definitions, code headers, and symbol data required by injection tools. 
A small modification was required to fix build issues encountered during patch development.
* **Modified file:** *gfl/core/gfl_heap.h*
* **Scope:** Toolchain / build system only
* **Impact on game logic:** None

This modification has been pushed to a maintained fork of *swan*, and this repository’s submodule references that fork.

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

This repository is intended for educational and research purposes only.

No proprietary game assets, binaries, or copyrighted material are included
or redistributed.

All trademarks and copyrighted materials belong to their respective owners.
