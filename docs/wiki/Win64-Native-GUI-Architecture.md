<h1>
  <img src="https://raw.githubusercontent.com/OmegaSoftDLL/omega-sovereign/main/docs/assets/omega-sovereign-badge.svg" alt="Omega Sovereign Emblem" width="76" height="76" align="left" />
  Win64 Native GUI Architecture — <code>OmegaSovereign_GUI.exe</code> (<code>50,176 B</code>) &amp; <code>OmegaSovereign_P33.exe</code> (<code>50,208 B</code>)
</h1>
<br clear="left"/>

`omega_pe64_gui_synth.src` synthesizes `OmegaSovereign_GUI.exe` (**`50,176` bytes**) and `OmegaSovereign_P33.exe` (**`50,208` bytes**) directly from **100% pure Lume `v1.1.0`** without invoking any external C/C++ compiler, system assembler, `link.exe`, or `rc.exe`.

---

## 1. Cyber-Obsidian Dark-Neon `GDI32` Rendering Engine

Inside `OmegaSovereign_GUI.exe`, the native x86-64 `WndProc` intercepts Win32 control-coloring messages (`WM_CTLCOLOREDIT = 307`, `WM_CTLCOLORLISTBOX = 308`, and `WM_CTLCOLORSTATIC = 312`) using `GDI32.dll` (`CreateSolidBrush`, `SetBkColor`, `SetTextColor`) to render a high-contrast **Cyber-Obsidian Dark-Neon Studio** (`1400×780` viewport):

| UI Surface / Control | Win32 Message / Class | Backdrop Color (Hex / `COLORREF`) | Text Color (Hex / `COLORREF`) |
| :--- | :--- | :--- | :--- |
| **Main Window Frame (`OmegaSovereignWin64Class`)** | `WNDCLASSEXA` frame brush | `#060C18` Cyber-Obsidian (`0x00180C06`) | — |
| **Pane 1..4 Section Headers & Bottom Status Bar** | `WM_CTLCOLORSTATIC` (`312`) | `#111F3D` Cyber Indigo (`0x003D1F11`) | `#FFBD38` Sovereign Gold-Amber (`0x0038BDFF`) |
| **Pane 1 & 3 Interactive ListBoxes (`5003`, `5004`)** | `WM_CTLCOLORLISTBOX` (`308`) | `#0A1428` Deep Cyber Navy (`0x0028140A`) | `#F0FAFC` Crisp Cyber Ice-White (`0x00FCFAF0`) |
| **Pane 2 & 4 Multiline Code/Telemetry Editors (`5002`, `5005`)** | `WM_CTLCOLOREDIT` (`307`) | `#0A1428` Deep Cyber Navy (`0x0028140A`) | `#38F5D4` Glowing Lume Emerald-Cyan (`0x00D4F538`) |

---

## 2. Declarative `@ui-layout` 4-Pane Geometry & Control Styles

Omega Sovereign `v5.0` pairs `omega_pe64_gui_synth.src` with `modules/ui_cyber_layout.lume` and `omega_ui_layout_manifest.json`, proving the `QF_LIA` split-pane pixel conservation law (`ui_split_conservation_law`) across both Win64 `PE32+` and WebAssembly DOM (`omega_cockpit.html` / `omega_web_dom.wasm`) targets:

- **10-Action Top Toolbar (`Segoe UI -12` Bold):** Direct hardware-accelerated command dispatch (`F5` Run Suite, `F6` Prove `QF_LIA`, `F7` Unit Tests, `F8` Launch 3D Cockpit, Open/Save Artifact, Forensic Hex Dump, P33 Shield).
- **Pane 1 (`5003`) & Pane 3 (`5004`) — Interactive `LISTBOX` Selectors:**
  - Exact Win32 Style: **`1412694337` (`0x54340141`)** = `WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_THICKFRAME | WS_VSCROLL | WS_HSCROLL | LBS_NOTIFY | LBS_HASSTRINGS`.
  - Supports simultaneous live border resizing (`WS_THICKFRAME`), mouse selection (`WM_COMMAND` -> `LBN_SELCHANGE`), and horizontal scrolling (`LB_SETHORIZONTALEXTENT = 680`).
- **Pane 2 (`5002`) & Pane 4 (`5005`) — Multiline `EDIT` Inspection Consoles:**
  - Exact Win32 Style: **`1412698308` (`0x543410C4`)** = `WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_THICKFRAME | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_WANTRETURN`.
  - Full-width layout decoding (`1366 px` interior span) ensures Pane 4 (`5005` live benchmark & assurance log) and the status bar (`5006`) dynamically resize with `WM_SIZE`.

---

## 3. Exact `PE32+` x86-64 Section Map (`50,176 B` & `50,208 B`)

| Section / Region | RVA | Raw Offset | Size (Bytes) | Role & Verification Details |
| :--- | :---: | :---: | :---: | :--- |
| **DOS + COFF + Optional `PE32+` Headers** | `0x0000` | `0` | `1,024 B` | `IMAGE_FILE_MACHINE_AMD64` (`0x8664`), `Subsystem = 2` (`WINDOWS_GUI`), ImageBase `0x400000` |
| **`.text` (Executable Machine Code)** | `0x1000` | `1,024` | `8,192 B` | Entry point (`start_init`), P33 MBA self-healing prologue, `WndProc`, `WM_SIZE` & `WM_CTLCOLOR*` handlers |
| **`.idata` (Import Address Table)** | `0x3000` | `9,216` | `4,096 B` | `KERNEL32.dll`, `USER32.dll`, `GDI32.dll`, `COMDLG32.dll`, and `SHELL32.dll` (`42` IAT thunk slots) |
| **`.data` (Inspection & Brush Slots)** | `0x4000` | `13,312` | `32,768 B` | UI strings, 16 interactive pillar/certificate dossier cards, `GDI32` brush handles (`XOR k=178` encrypted in P33) |
| **`.rsrc` (Win32 Resource Directory)** | `0xC000` | `46,080` | `4,096 B` | `1,128`-byte 32-bit BGRA **Lumi** mascot icon (`RT_ICON` + `RT_GROUP_ICON`) + DPI-aware Common Controls v6 `RT_MANIFEST` |
| **`LUME_SEAL` Trailer (`P33` Only)** | — | `50,176` | `+32 B` | Appended to `OmegaSovereign_P33.exe` (`50,176 + 32 = 50,208` bytes total) |

---

## 4. Verified Collections & Sovereign Triad Integration

- **Compile-Time Collection Invariants:** `vec_clamp_index`, `vec_checked_slice_len`, `map_checked_slot`, `std_clamp`, `decimal_clamp`, and `vec_slice_conservation_law` guarantee zero out-of-bounds panics across UI and telemetry buffers.
- **Sovereign Triad Sentinel (`omega_sovereign_triad_capsule.json` & `modules/triad_safety_envelope.lume`):** Coordinates `daemon-triad` (`< 100 ms` incremental verification & 3-node P2P quorum), `hot-evolve` (zero-downtime E-Graph equality-saturation swap), and `live-cockpit` (`omega_cockpit.html` real-time visualization).
