# Pokémon BW2 – Flag System Technical Notes

> **Scope**
> These notes describe the internal flag system used in Pokémon Black 2 / White 2 (Nintendo DS, Gen V).
> The focus is on understanding how flags are structured, stored, and managed by the engine,
> including daily-reset flags and unused ranges.
> No proprietary game code or assets are included.

---

## 1. What Is a Flag?

A **flag** is a binary state variable used by the game engine to track progression,
events, and conditional behavior.

A flag can only have two states:

- `0` → Disabled / False  
- `1` → Enabled / True  

Flags are used extensively in:

- Story progression
- NPC interaction control
- Event gating
- Item acquisition tracking
- One-time triggers
- Daily events

Flags are part of the game's internal state management system.

---

## 2. Conceptual Model

At engine level, flags are stored as **bitfields** inside structured save data blocks.

Instead of storing each flag as a full byte, the engine packs flags efficiently:

- 1 flag = 1 bit
- 8 flags = 1 byte

This allows thousands of flags to be stored compactly.

Example (conceptual):
Byte: 00010010
Bit index: 7 6 5 4 3 2 1 0

Each bit represents a different flag ID.

---

## 3. Flag Usage in Game Logic

Flags are typically:

- Set after completing an event
- Checked before executing script branches
- Cleared when resetting conditional states (in specific cases)

Example logic (conceptual):
If Flag 500 == 0:
    Give Item
    Set Flag 500
Else:
    Show alternate message

Flags therefore serve as **persistent state gates**.

---

## 4. Flags in Scripts

In Gen V scripting systems (e.g., BeaterScript or raw script commands):

Common operations include:

- `CheckFlag`
- `SetFlag`
- `ClearFlag`

Script execution flow often depends entirely on flag checks.

Flags allow:

- One-time NPC rewards
- Unlocking map areas
- Preventing repeated cutscenes
- Enabling post-game content

---

## 5. Internal Allocation

Flags are allocated within specific ID ranges.

Example unused standard flags in B2W2:

| Hex ID | Decimal ID |
|--------|------------|
| 0x1F4  | 500        |
| 0x1F5  | 501        |
| 0x1F6  | 502        |
| 0x1F7  | 503        |
| ...    | ...        |
| 0x20E  | 526        |

These flags are generally safe for custom use when confirmed unused.

> Always verify unused status before repurposing a flag.

---

## 6. Daily Flags

### 6.1 What Are Daily Flags?

**Daily flags** are special flags that automatically reset
once per real-world day.

They are used for:

- Daily NPC rewards
- Once-per-day interactions
- Swarm events
- Daily hidden items
- Seasonal mechanics

Unlike normal flags, daily flags are:

- Set during gameplay
- Cleared automatically by the engine’s daily reset routine

---

### 6.2 Daily Flag Ranges (B2W2)

Based on reverse-engineering research:

In Pokémon Black 2 / White 2:

- Daily flags appear in the approximate range: 2720 – 2819


It is believed that:

- `2794 – 2819` are fully unused
- These are safest for custom daily mechanics

> Caution: Some flags outside scripts may be referenced programmatically.

---

### 6.3 Daily Flags in BW1

In Pokémon Black / White:

Daily unused flags appear in the range: 2765 – 2911

This provides significantly more available daily flags
compared to B2W2.

---

## 7. Engine-Level Handling

The daily reset routine likely:

1. Compares current RTC date with stored save date
2. If date changed:
   - Clears daily flag bitfield range
   - Updates stored date

This process occurs automatically during game initialization.

Daily flags are therefore:

- Persistent across saves
- Cleared by engine logic, not scripts

---

## 8. Flags vs Variables

It is important to distinguish:

| Flags | Variables |
|-------|----------|
| Binary (0/1) | Numeric values |
| 1 bit storage | Multi-byte storage |
| Used for gating | Used for counters |
| Fast checks | More flexible logic |

Use flags when:
- Tracking completion
- Preventing repetition
- Gating conditions

Use variables when:
- Counting items
- Tracking numeric progression
- Storing dynamic values

---

## 9. Best Practices for Custom Flags

When creating custom mechanics:

- Use confirmed unused ranges
- Prefer high unused IDs (e.g., 2794–2819 for daily flags)
- Avoid low-ID flags unless verified safe
- Document every custom flag used
- Keep a flag allocation table in your project

Example documentation format:

| Flag ID | Purpose |
|----------|----------|
| 500 | Arancino event completion |
| 501 | Level Cap system |
| 2794 | Custom daily reward |

---

## 10. Common Failure Modes

| Symptom | Cause |
|----------|--------|
| Event triggers repeatedly | Flag never set |
| Event never triggers | Flag pre-set unexpectedly |
| Daily event never resets | Using non-daily flag |
| Random behavior | Flag collision with existing system |

---
## 11. Flag Categories

Flags in Gen V can be broadly divided into:

- Story progression flags
- System flags (engine-controlled)
- Daily reset flags
- Map/event local flags

## 12. Summary

- Flags are binary state markers stored as bitfields
- They control progression, gating, and one-time events
- Daily flags reset automatically each day
- B2W2 daily flags range approximately from 2720–2819
- 2794–2819 appear to be safest unused daily flags
- Always document and verify custom flag usage

Proper flag management is critical for stable ROM modifications.
Incorrect usage may cause softlocks, broken events, or progression bugs.
