<h1>
  <img src="https://raw.githubusercontent.com/OmegaSoftDLL/omega-sovereign/main/docs/assets/omega-sovereign-badge.svg" alt="Omega Sovereign" width="76" height="76" align="left" />
  Win64 Native GUI Architecture — <code>OmegaSovereign_GUI.exe</code> <code>v4.0</code> (Cyber-Obsidian Dark Neon Studio)
</h1>
<br clear="left"/>

`omega_pe64_gui_synth.src` synthesizes `OmegaSovereign_GUI.exe` (`33,792` bytes) and `OmegaSovereign_P33.exe` (`33,824` bytes) directly from 100% pure Lume without any C/C++ compiler, linker (`link.exe`), or resource compiler (`rc.exe`).

---

## 1. Cyber-Obsidian Dark Neon GDI32 Rendering Engine

In **OmegaSovereign `v4.0`**, `WndProc` natively intercepts Win32 control-coloring messages (`WM_CTLCOLOREDIT = 307`, `WM_CTLCOLORLISTBOX = 308`, and `WM_CTLCOLORSTATIC = 312`) using `GDI32.dll` (`CreateSolidBrush`, `SetBkColor`, `SetTextColor`) to render a high-contrast **Cyber-Obsidian Dark Neon Studio**:

| UI Surface / Control | Win32 Message / Class | Background Color (Hex / `COLORREF`) | Foreground Text Color (Hex / `COLORREF`) |
| :--- | :--- | :--- | :--- |
| **Main Window Frame (`OmegaSovereignWnd`)** | `WNDCLASSEXA.hbrBackground` | `#060C18` Cyber-Obsidian (`0x00180C06`) | — |
| **Quadro 1..4 Headers & Bottom Status Bar** | `WM_CTLCOLORSTATIC` (`312`) | `#111F3D` Cyber Indigo (`0x003D1F11`) | `#FFBD38` Sovereign Gold-Amber (`0x0038BDFF`) |
| **Quadro 1 & 3 Interactive ListBoxes (`5003`, `5004`)** | `WM_CTLCOLORLISTBOX` (`308`) | `#0A1428` Deep Cyber Navy (`0x0028140A`) | `#F0FAFC` Crisp Cyber Ice-White (`0x00FCFAF0`) |
| **Quadro 2 & 4 Multiline Code/Telemetry Editors (`5002`, `5005`)** | `WM_CTLCOLOREDIT` (`307`) | `#0A1428` Deep Cyber Navy (`0x0028140A`) | `#38F5D4` Glowing Lume Emerald-Cyan (`0x00D4F538`) |

---

## 2. Declarative `@ui-layout` 4-Pane Geometry & Control Styles

`omega-sovereign v4.0` pairs `omega_pe64_gui_synth.src` with the declarative `@ui-layout` engine (`omega_ui_layout_manifest.json`), enforcing the `QF_LIA` split-pane conservation law (`ui_split_conservation_law`) across all 4 resizable/scrollable studio panes:

- **Top Menu Bar Disabled (`hMenu = 0`):** Eliminates any overlap with the 10-button `Segoe UI -12` (`600` semi-bold) quick-action toolbar (`116px–142px` buttons).
- **Quadro 1 (`5003`) & Quadro 3 (`5004`) — Interactive `LISTBOX` Panes:**
  - Exact Win32 Style: **`1412694337` (`0x54340141`)** = `WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_THICKFRAME | WS_VSCROLL | WS_HSCROLL | LBS_NOTIFY | LBS_HASSTRINGS`.
  - Enables simultaneous `WS_THICKFRAME` live border resizing, `LBS_NOTIFY | LBS_HASSTRINGS` mouse click selection (`WM_COMMAND` -> `LBN_SELCHANGE`), and horizontal scrolling (`LB_SETHORIZONTALEXTENT = 680`).
- **Quadro 2 (`5002`) & Quadro 4 (`5005`) — Multiline `EDIT` Panes:**
  - Exact Win32 Style: **`1412698308` (`0x543410C4`)** = `WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_THICKFRAME | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_WANTRETURN`.
  - Full-width decoding (`if w_raw == 999 then 1366 else w_raw`) ensures Quadro 4 (`5005`, 14-line scrollable telemetry log) and the status bar (`5006`) span the full `1366px` interior width of the `1400x780` window.

---

## 3. PE32+ x86-64 Section Map & Lume `v1.1.0` Language Integration

- **PE32+ Sections (`33,792` bytes total):**
  - `.text` (`8,192 B` at RVA `0x1000`): Native x86-64 machine code (`start_init` + `WndProc` dark-mode brush dispatch + live engine execution).
  - `.idata` (`4,096 B` at RVA `0x3000`): Import Address Table for `KERNEL32.dll`, `USER32.dll`, `GDI32.dll`, `COMDLG32.dll`, and `SHELL32.dll`.
  - `.data` (`16,384 B` at RVA `0x4000`): Slot table (`40..130+`) holding strings, layout coordinates, GDI brush handles, and P33 `XOR k=178` payload in `OmegaSovereign_P33.exe` (`33,824` bytes).
  - `.rsrc` (`4,096 B` at RVA `0x8000`): Embedded `1,128`-byte 32-bit BGRA **Lumi** mascot icon (`RT_ICON` ID `1` + `RT_GROUP_ICON` ID `1`) + Win32 Common Controls v6 DPI-aware manifest (`RT_MANIFEST` ID `1`).
- **Integrated Lume `v1.1.0` Capabilities in `v4.0`:**
  - **Verified Generic Collection Invariants:** `vec_clamp_index`, `vec_checked_slice_len`, `map_checked_slot`, `std_clamp`, and `vec_slice_conservation_law`.
  - **Wave 10 Sentient Triad Capsule (`omega_wave10_triad_capsule.json`):** `daemon-triad` (`<100ms` P2P gossip sentinel), `hot-evolve` (E-Graph zero-downtime swap), and `live-cockpit` (Episode `#3,124`, `114,226` laws).
  - **Universal Chameleon 9-Ecosystem Live Action (`[I0003]`) & Frontier Artifacts:** Live C, Rust, Python DLPack, Node.js/WASM, and SQL/OpenAPI bridges + `@neural-kernel` Verilog RTL (`omega_neural_autodiff.v`) + `DNA4` (`omega_genome_storage.dna4`) + `OpenQASM 3.0` (`omega_quantum_bell.qasm`) + `CEGIS` 0ms self-healing.
