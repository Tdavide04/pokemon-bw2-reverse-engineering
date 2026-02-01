# Modifications and Applied Patches

This document tracks the gameplay changes, patches, and data edits applied to the project. It is intended as a **technical changelog** and reference for future maintenance or debugging.

---

## 1. Evolution Modifications

Several Pokémon evolutions were modified to remove trade requirements or adjust evolution conditions to be achievable through level-up or item-based progression.

| Pokémon    | Evolves Into | New Condition                             |
| ---------- | ------------ | ----------------------------------------- |
| Poliwhirl  | Politoed     | Level up while holding **King’s Rock**    |
| Kadabra    | Alakazam     | Level 27                                  |
| Machoke    | Machamp      | Level 36                                  |
| Graveler   | Golem        | Level 36                                  |
| Slowpoke   | Slowking     | Level up while holding **King’s Rock**    |
| Haunter    | Gengar       | Level 35                                  |
| Onix       | Steelix      | Level up while holding **Metal Coat**     |
| Rhydon     | Rhyperior    | Level 40                                  |
| Seadra     | Kingdra      | Level up while holding **Dragon Scale**   |
| Scyther    | Scizor       | Level up while holding **Metal Coat**     |
| Electabuzz | Electivire   | Level up while holding **Electirizer**    |
| Magmar     | Magmortar    | Level up while holding **Magmarizer**     |
| Porygon    | Porygon2     | Level up while holding **Upgrade**        |
| Porygon2   | Porygon-Z    | Level up while holding **Dubious Disc**   |
| Feebas     | Milotic      | Level up while holding **Dragon Scale**   |
| Dusclops   | Dusknoir     | Level up while holding **Reaper Cloth**   |
| Clamperl   | Huntail      | Level up while holding **Deep Sea Tooth** |
| Clamperl   | Gorebyss     | Level up while holding **Deep Sea Scale** |
| Boldore    | Gigalith     | Level 36                                  |
| Gurdurr    | Conkeldurr   | Level 36                                  |
| Karrablast | Escavalier   | Level 25                                  |
| Shelmet    | Accelgor     | Level 25                                  |

These changes were implemented by modifying evolution tables and removing trade-only evolution flags where applicable.

---

## 2. Custom Flags

The following custom game flags were introduced:

| Flag ID | Name     | Purpose                      |
| ------- | -------- | ---------------------------- |
| 500     | Arancino | Custom gameplay / story flag |
| 501     | LvlCap   | Level cap control logic      |

These flags are used by custom scripts and engine logic to gate or enable specific behaviors.

---

## 3. Text Modifications

Several in-game text entries were edited to reflect new mechanics, features, or balance changes.

Modified text IDs:

* 111 -> **Day-Care Couple** -> **Egg Dispenser**
* 172 -> **Pokemon Center of Aspertia City** -> **Arancino's dialogue**
* 380 -> **UX Pokemon Stats** -> **New design**
* 433 -> **HM Global Script** -> **New dialogue**
* 479 -> **PC Global Script** -> **New dialogue**

All edits were applied directly to the text resource files and verified in-game.

---

## 4. Move Set Adjustments

* **Gastly** now starts with the move **Clear Smog**.

This change was made to improve early-game utility and balance.

---

## 5. New Gameplay Features

### Egg Dispenser

* An **egg dispenser** has been added to the game.
* The dispenser provides eggs without the need for breeding mechanics.

## Quality of Life Changes

* **HM moves no longer need to be taught to Pokémon.**
  * Simply having the corresponding HM item in the player's bag is enough to use the field action.

* **Removed Gym Badge restrictions** on Pokémon obedience.

* **Increased Shiny encounter rates.**

* **Reduced steps required to hatch eggs.**

---

## 6. Notes

* All changes were tested both in emulator and on real hardware where applicable.
* No original game assets or proprietary binaries are included in this repository.

---

## Legal Notice

This document is intended for educational and research purposes.
No proprietary game assets, binaries, or copyrighted material
are included or distributed.

All trademarks belong to their respective owners.

