# Pokémon Gen V – Icon Palette Array Technical Notes

> **Scope**
> These notes describe the internal structure and behavior of the icon palette array used in Pokémon Black/White and Black 2/White 2 (Nintendo DS, Gen V).
> The goal is to identify the array's location within the `arm9.bin` file to allow editing the palette assignments for individual Pokémon or Fakemon.

---

## 1. Overview
In Generation V, every Pokémon displays an icon in menus and boxes. The game assigns each species a specific palette chosen from three predefined variants (Palette 0, 1, or 2). This association is managed via a **Value Array** located within the game's main binary.

Modifying this array is essential for who need specific colors for new Pokémon icons without altering the actual graphical files.

---

## 2. Prerequisites
To find and edit the array, you will need the following tools:
* **Tinke:** To extract files from the ROM.
* **BLZ Decompressor:** To decompress the `arm9.bin` file (required if you are not using tools like CTRMap that handle decompression automatically).
* **Hex Editor:** (e.g., HxD) To modify the hexadecimal values.
* **FrostGen5Tool:** For visual verification of current palette assignments.

---

## 3. Extraction and Decompression
The array resides within the main processor binary (`arm9.bin`).

1. Open your ROM with **Tinke**.
2. Navigate to: `root -> ftc -> arm9.bin`.
3. Extract the file.
4. **Decompression:** The file must be decompressed to expose the raw hex data.
   * Use the Python script `decompress_arm9.py` provided in this repo in [Scripts].

---

## 4. Identifying the Palette Array
The array is structured as a sequence of bytes where each value corresponds to the palette index used by the Pokémon, following the National Pokédex order.

### Search Pattern
To find the start of the array, open the decompressed `arm9.bin` with a Hex Editor and search for the following hex string:
`00 11 11 11 00 00 00`

### Array Structure
The structure follows the National Dex index:

| Hex Value | Pokémon / Entry | Description |
| :--- | :--- | :--- |
| `00` | Index 0 | Array Start (Placeholder) |
| `11` | Bulbasaur | Uses Palette 1 |
| `11` | Ivysaur | Uses Palette 1 |
| `11` | Venusaur | Uses Palette 1 |
| `00` | Charmander | Uses Palette 0 |
| `00` | Charmeleon | Uses Palette 0 |
| `00` | Charizard | Uses Palette 0 |

---

## 5. Editing Values
Each byte in the array determines which palette is loaded for the icon:
* `00` → Palette 0 
* `11` → Palette 1
* `22` → Palette 2

By changing these values, you can force the game to load a different palette for a specific Pokémon without editing the sprite files themselves.

---

## 6. Known Offsets
If you are working on clean (vanilla) ROMs, you can jump directly to these offsets in the decompressed `arm9.bin`:

| Game Version | Offset |
| :--- | :--- |
| **Pokémon Black** | `0x9A474` |
| **Pokémon White** | `0x9A48C` |
| **Pokémon Black 2** | `0x8C54C` |
| **Pokémon White 2** | `0x8C578` |

---

## 7. Visual Verification
To confirm which palette a Pokémon is currently using before editing:
1. Open the ROM with **FrostGen5Tool**.
2. Go to **Pokemon Editor** -> **Sprite Editor**.
3. Select the desired Pokémon to see the assigned palette index.

---

## 8. Best Practices
* **Backup:** Always create a backup of your `arm9.bin` before making hexadecimal changes.
* **Alignment:** Ensure the file is properly decompressed; otherwise, the hex search will return no results.
* **Testing:** After editing, re-insert the `arm9.bin` into the ROM using Tinke and launch the game to verify the icons in the PC boxes.

> **Note**
> Incorrect modifications to `arm9.bin` can cause the game to crash immediately on boot (White Screen). If this occurs, verify that you haven't altered the file size during saving or corrupted the offset table during recompression.