# In-Game Debugging with IDA Pro - Technical Notes

## Overview

Debugging injected or modified game code follows the same fundamental principles as traditional software debugging. When injected code behaves incorrectly or causes crashes, the only reliable way to understand *why* is to observe execution at runtime. In the context of games, this typically means attaching a debugger to a running instance and inspecting which functions are executed, in which order, and with which state.

IDA Pro, when combined with an emulator exposing a GDB stub (e.g. DeSmuME for Nintendo DS), allows full **in‑game debugging**. This makes it possible to track function calls while playing, inspect registers and memory, and verify whether hooks and patches behave as intended.

These notes focus on using IDA Pro as a **runtime debugger** to assist with:

* validating code injection
* identifying which game functions are executed during gameplay
* debugging crashes or incorrect behavior caused by patches

---

## Debugging Philosophy

Debugging injected game code is not fundamentally different from debugging any other program:

* If something breaks, execution must be observed.
* If behavior is unexpected, assumptions must be verified.
* Tooling and workflows may differ, but the reasoning process is the same.

The perceived difficulty usually comes from:

* unfamiliarity with the game’s codebase
* lack of documentation
* the need to understand both the debugger (IDA) and the game‑specific injection system

This is normal and expected when working in a reverse‑engineering context.

---

## Required Tools

* **IDA Pro**

  * Used to load analyzed binaries (IDB/IDAPRO database)
  * Provides disassembly, symbols, breakpoints, and live debugging

* **DeSmuME (with ARM9 GDB stub enabled)**

  * Acts as the runtime environment
  * Exposes the game process to external debuggers

* **Analyzed IDB / ESDB**

  * A database representing the loaded ARM9 segments
  * Required for meaningful symbols and navigation during debugging

---

## Environment Setup

### 1. Open the IDB in IDA Pro

Open the IDA database corresponding to the segment you want to debug. Any relevant ARM9 segment is acceptable, as long as it matches the code currently loaded in memory.

Example:

* `Field.idb` representing the field engine code

### 2. Launch DeSmuME with GDB Stub

From a command prompt in the DeSmuME directory:

```
DeSmuME.exe --arm9gdb <port>
```

* Commonly used port: `25000`
* Any unused port is acceptable

### 3. Disable Dynamic Recompiler

In DeSmuME:

```
Config → Emulation Settings → Disable Dynamic Recompiler
```

This is mandatory for reliable debugging and breakpoint behavior.

### 4. Load the ROM

Load the game ROM in DeSmuME.

At this stage:

* the game is loaded in memory
* execution is **paused**
* it will not start until a debugger attaches

---

## Attaching IDA to the Emulator

1. Return to IDA Pro
2. Click the **Play / Run** button
3. If connection fails:

   * Set address to `localhost`
   * Set port to the same port used when launching DeSmuME
4. Confirm attachment when prompted

Once attached:

* **Play** resumes game execution
* **Pause** halts execution
* **Stop** detaches the debugger from the emulator

IDA now has full control over the game’s execution state.

---

## Runtime Function Debugging

### Locating a Target Function

To debug a specific behavior, identify the function involved in the logic you are modifying or hooking.

Example:

* `BagSave_AddItemCore`

Steps:

1. Open the **Functions** window in IDA
2. Locate the target function by name
3. Double‑click to jump to its entry point

### Setting a Breakpoint

* Right‑click on the function entry
* Set a breakpoint at the first instruction

Behavior:

* Whenever the game calls this function, execution will halt
* Registers, stack, and memory can be inspected

This is essential for verifying that:

* the function is actually reached
* hooks are executed at the correct time

---

## Debugging Injected Hooks

When a function is hooked at its entry point using assembly‑level injection:

* The injection system typically overwrites the original prologue
* A **branch instruction** is inserted
* Execution is redirected to custom code

During debugging:

* The injected branch may not be immediately obvious in static view
* Once the breakpoint is hit, IDA will reveal the actual instruction flow

Key things to verify:

* the branch target address
* correct register preservation
* correct return path back to original code

This step is critical for diagnosing crashes or silent logic failures.

---

## Practical Use During Gameplay

With IDA attached:

* You can play the game normally
* Execution halts automatically when breakpoints are reached
* This allows you to correlate **in‑game actions** with **code execution**

Typical use cases:

* Identifying which functions are triggered by specific player actions
* Confirming that patched logic runs at the correct moment
* Observing side effects caused by injected code

This transforms gameplay into a controlled debugging session.

---

## Notes on Complexity

Debugging in this context requires:

* understanding IDA’s interface
* understanding the game’s execution model
* understanding the injection framework

While this adds complexity, it is unavoidable in any non‑trivial reverse‑engineering or modding effort. The skills developed here are transferable to:

* other games
* other engines
* other low‑level debugging environments

---

## Summary

Using IDA Pro as an in‑game debugger enables:

* real‑time observation of function calls
* precise verification of hooks and patches
* systematic debugging of injected code

Despite the lack of a single, all‑encompassing guide, this workflow represents the standard and most reliable approach to debugging game code at runtime.

## Legal Notice

This document is intended for educational and research purposes.
No proprietary game assets, binaries, or copyrighted material
are included or distributed.

All trademarks belong to their respective owners.
