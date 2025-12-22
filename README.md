# VS Menu (Vampire Survivors Overlay)

A small in-game overlay for Vampire Survivors that lets you view/tweak a bunch of run-time stuff.

In the beginning it was only intended to be a stat editor, hence the repo name but ended up poking at several more things as time went on :)

<img width="318" height="1199" alt="image" src="https://github.com/user-attachments/assets/0a817ad1-774d-4a9e-a32f-74731545d140" />

---

## What it does

### Character tab
- **Character selector** for selecting between either yourself (default) or any other NPC or friend(s) playing alongside you :)
- Quick toggles:
  - God Mode
  - One Hit Kills
  - Random Level Up
  - Limit Break + Random Limit Break
- Live editable values:
  - Level, XP, Kills, Gold, Session Gold
  - Max Weapons, Max Passives
- Player stats editing:
  - Max Health, Recovery, Armor, Move Speed
  - Might, Projectile Speed, Duration, Area
  - Cooldown, Amount
  - Revivals left / used
  - Magnet radius
- Pickup mode popup:
  - Normal
  - Gems and Coins Only
  - Gems, Coins and Roasts
  - Gems, Coins, Roasts and Souls
  - Ignore All

Also shows per second deltas for levels, xp, kills and gold.

### Music tab
- Song list with:
  - Search filter
  - Tooltips for song credit(s)
  - Auto scroll to the selected track when you enter the tab and when changing the song via the random option or previous/next buttons.
- Controls:
  - Stop Music
  - Previous / Next
  - Jump to a Random Track
- Modifiers:
  - Forsaken (slower and pitched down)
  - Normal
  - Hyper (faster and pitched up)

### Engine tab
- Camera zoom
- Timescale control
- SFX Volume + Music Volume
- Survived time display/edit (shows formatted time, manual edit uses raw seconds as float)

### Misc tab
- Accent color picker that immediately re-applies the full theme
- Log console: (for development but left it in anyways)
  - Clear log
  - Auto scroll
  - Errors-only filter
  - Search filter
  - Click a log line to copy it to clipboard

---

## Build notes
- **Language(s):** C++ (MASM available if needed)
- **IDE:** Visual Studio 2026
- **UI:** Dear ImGui
- **Renderer:** DirectX 11
- **Platform:** Windows
- **Tested on:** Steam

To build this repo, install PolyHook2 via vcpkg (`polyhook2:x64-windows-static`), or replace the hooking layer with your own implementation.

---

## Safety
This is a runtime modding tool. You can absolutely break a run if you push values too far since I don't clamp most things!

---

## Roadmap (if i feel like it one day)
- more Engine tab stuff as it's kinda bare compared to the rest of the tabs

---

## Credits
- Dear ImGui
- PolyHook2
- Vampire Survivors (for being fun to play and poke at)
- [@veteri](https://github.com/veteri) for getting me into the game in the first place by gifting me the game/dlc <3

## Found this useful?
[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/R6R81MZ47Q)
