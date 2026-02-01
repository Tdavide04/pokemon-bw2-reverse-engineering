# ESDB – Technical Notes

## What is an ESDB

An **ESDB (External Symbol DataBase)** is a structured **metadata file** that maps **symbolic names** (functions, labels, global symbols) to their **runtime memory addresses**, together with **segment information** (ARM9, overlays, ITCM, etc.), in
Nintendo DS reverse‑engineering and code injection workflows.

An ESDB:

* does **not** contain executable code
* does **not** contain ROM data or binary blobs
* does **not** allow reconstruction of the original program

It is purely a *symbol resolution layer*.

---

## Purpose and Role

The ESDB acts as an interface between:

* **custom injected code** (C/C++/ASM)
* the **precompiled game executable**

Tools such as **CTRMap** and **RPMTool** rely on the ESDB to:

* resolve function names to absolute addresses
* determine the correct **memory segment** for a relocation
* safely generate hooks without hardcoding addresses

Without an ESDB, all injections would require manual address management, which is error‑prone and difficult to maintain.

---

## ESDB Generation Workflow

A typical ESDB generation pipeline is:

1. Reverse-engineering the ROM using a static analysis tool (e.g. IDA)
2. Exporting symbols via a linker-style MAP file
3. Converting the MAP and segment metadata into ESDB format

The output is a YAML‑based ESDB file consumable by CTRMap/RPM tooling.

---

## ESDB File Structure

### Segments

Segments define discrete memory regions where symbols may reside, such as:

* ARM9 executable region
* ITCM / DTCM
* static RAM
* overlay modules

Segment data is required to:

* prevent relocations from being applied to incorrect overlays
* disambiguate overlapping memory regions
* ensure deterministic patching behavior

---

### Symbols

Each symbol entry includes:

* **Name** – symbolic identifier of the function or label
* **Segment** – segment ID where the symbol resides
* **Address** – absolute runtime address

On ARM architectures:

* **odd addresses indicate Thumb mode**
* **even addresses indicate ARM mode**

This distinction is critical for correct relocation encoding.

---

## Relationship Between ESDB and Code Injection

ESDBs enable **automatic relocation derivation** based on symbol naming conventions.

Example:

`THUMB_BRANCH_BagSave_AddItem`

The toolchain will:

1. parse the relocation type (`THUMB_BRANCH`)
2. resolve `BagSave_AddItem` via the ESDB
3. extract its segment and address
4. generate the appropriate branch instruction
5. apply the relocation at runtime

The ESDB therefore serves as the authoritative source of truth for hook targets.

---

## ESDB vs Relocation YML

| ESDB                         | Relocation YML             |
| ---------------------------- | -------------------------- |
| Symbol database              | Patch description          |
| Passive metadata             | Active modification logic  |
| No runtime effect by itself  | Alters executable behavior |
| Required for automatic hooks | Optional / manual          |

---

## Common Pitfalls

* Mismatching ARM vs Thumb relocation types
* Incorrect segment assignment
* Assuming ESDBs perform injections (they do not)
* Publishing raw IDA databases or MAP files

---

## Summary

* **ESDBs provide symbol resolution for code injection**
* **They enable safe, maintainable, and automated hooking**
* **They contain metadata only and no executable code**

An ESDB is a foundational component for robust Nintendo DS code injection workflows.

## Legal Notice

This document is intended for educational and research purposes.
No proprietary game assets, binaries, or copyrighted material
are included or distributed.

All trademarks belong to their respective owners.

