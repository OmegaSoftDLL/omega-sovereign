<h1>
  <img src="https://raw.githubusercontent.com/OmegaSoftDLL/omega-sovereign/main/docs/assets/omega-sovereign-badge.svg" alt="Omega Sovereign" width="76" height="76" align="left" />
  Win64 Native GUI Architecture (<code>OmegaSovereign_GUI.exe</code>)
</h1>
<br clear="left"/>

`omega_pe64_gui_synth.src` synthesizes `OmegaSovereign_GUI.exe` (`33,792` bytes) and `OmegaSovereign_P33.exe` (`33,824` bytes) directly from pure Lume without any C/C++ compiler or resource compiler (`rc.exe`).

## Key PE32+ x86-64 Engineering Highlights

- **Sections:** `.text` (`8,192 B` at RVA `0x1000`), `.idata` (`4,096 B` at RVA `0x3000`), `.data` (`16,384 B` at RVA `0x4000`), `.rsrc` (`4,096 B` at RVA `0x8000`).
- **Embedded Lumi Mascot Icon (`RT_ICON` + `RT_GROUP_ICON`):** `1,128`-byte 32-bit BGRA icon loaded via `LoadIconA(hInstance, 1)` in `start_init` (`348` bytes <= `352`-byte `b_start` budget).
- **4 Resizable & Scrollable Panes (`1366px` Full Bottom Width):**
  - `LISTBOX` Panes (`5003` & `5004`): Style `1412702209` (`WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_BORDER | WS_THICKFRAME | WS_VSCROLL | WS_HSCROLL | LBS_NOTIFY | LBS_HASSTRINGS | LBS_DISABLENOSCROLL`) + `LB_SETHORIZONTALEXTENT = 680`.
  - `EDIT` Panes (`5002` & `5005`): Style `1412698308` (`WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_BORDER | WS_THICKFRAME | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_WANTRETURN`).
  - Full-width decoding (`if w_raw == 999 then 1366 else w_raw`) ensures the bottom telemetry console (`5005`) and status bar (`5006`) span the entire `1366px` width of the `1400x780` window.
