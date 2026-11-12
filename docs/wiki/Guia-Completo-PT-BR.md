<h1>
  <img src="https://raw.githubusercontent.com/OmegaSoftDLL/omega-sovereign/main/docs/assets/omega-sovereign-badge.svg" alt="Omega Sovereign Emblem" width="76" height="76" align="left" />
  Guia Institucional Completo do Omega Sovereign <code>v5.0</code> (<code>PT-BR</code>)
</h1>
<br clear="left"/>

O **Omega Sovereign `v5.0` (Edição 2026)** é o Command Center Desktop Nativo Windows 64-bit (`OmegaSovereign_GUI.exe` de **`50.176` bytes** e `OmegaSovereign_P33.exe` de **`50.208` bytes**), Estúdio de Garantia Binária Pós-Compilação e Estação de Trabalho Multimodal de IA construído **100% em [Lume `v1.1.0`](https://github.com/OmegaSoftDLL/Lume) puro** (`Zero C / Zero C++ / Zero Rust / Zero Python / Zero Linker Externo`).

---

## 1. Resumo dos 12 Pilares Arquiteturais (`v5.0`)

1. **`[01]` Compilador Zero-C (`stage2 == stage3`), *Wheeler DDC* e Síntese Direta `PE32+`:** Geração nativa de `OmegaSovereign_GUI.exe` (`50.176 B`) e `OmegaSovereign_P33.exe` (`50.208 B` com `.data` cifrado em `XOR k=178` + prólogo MBA).
2. **`[02]` `OmniProof-v4` e Kernel Independente `lcert --check-source`:** Provas estáticas `QF_LIA` (duais de Farkas), `QF_NIA` (`x * x >= 0`), `QF_BV`, octógonos, `@bound` WCET (`[V0002]`), `/ pure` (`[E0200]`) e `@no_alloc` (`[E0210]`) vinculadas ao SHA-256 e à AST.
3. **`[03]` Garantia Binária Simbólica Pós-Codegen:** Validação de tradução `ltv` (correlação 1-para-1 de desvios e checagem `[C0010]` *constant-time*), prova dos `18/18` helpers `ltv_rt`, solver *clean-room* `lsmt` (`unsat` em `omega_compute_core.smt2`), **`0` condições MC/DC descobertas** (`lmcdc`) e limite exato de bytes de pilha (`lstack`).
4. **`[04]` Criptografia *Constant-Time* `[C0011]`, PKI X.509v3 Ed25519, Entropia NIST SP 800-90B e TLS 1.3.**
5. **`[05]` Envelope `2oo2D` *Clean-Room* `RV32IM` (`safety_bundle/`), Memória em 4 Níveis (`31,8×`) e Concorrência Linear (`[E0305]`, `[E0306]`).**
6. **`[06]` Camaleão Poliglota para 9 Ecossistemas (`[I0003]`), Pré-Processador C `--preprocess` e Linux `io_uring`.**
7. **`[07]` `LumePuter` / `LumePU` em Pesos `.safetensors` (`RV32IM_Zba`) e `OpenTPU`.**
8. **`[08]` Roteador Híbrido Local de IA Multimodal e Ternária `1,58-Bit` (`Bonsai`, `Gemma 4 E2B`, `Ministral 3 3B`, `Liquid LFM3`, `Colibri` MoE, `VKPromos` CEGIS).**
9. **`[09]` Campo Unificado Ciberfísico (`UFE`), Fronteira $\Omega$ (`OTE`) e Malha Industrial IEC 62443 `Omega-Mesh`.**
10. **`[10]` FinTech Brasileira (`SEFAZ NF-e`, `BACEN Pix CobV`, CNPJ Alfanumérico Julho 2026) e Forense `AEGIS` `STIX 2.1`.**
11. **`[11]` Silício `@neural-kernel` (`CUDA PTX` / `Vulkan SPIR-V` / `Verilog RTL`), `DNA4`, Computação Quântica `[[9,1,3]]` QEC e Kernel Ring-0 (`omega_rtc.kernel`).**
12. **`[12]` Estúdio Win64 `@ui-layout` Cyber-Obsidian, Coleções Provadas (`Vec`/`Map`/`std_clamp`), Cockpit 3D (`omega_cockpit.html`) e Sentinela Tríade (`omega_sovereign_triad_capsule.json`).**

---

## 2. Como Executar no Windows (PowerShell)

```powershell
# Executar o Estúdio Nativo Win64 Cyber-Obsidian (50.176 bytes)
Start-Process .\OmegaSovereign_GUI.exe

# Executar a Edição Blindada P33 (50.208 bytes)
Start-Process .\OmegaSovereign_P33.exe

# Abrir o Cockpit 3D HTML5 + SVG + WebAssembly
Start-Process .\omega_cockpit.html
```

---

## 3. Como Verificar Provas, Garantias Binárias e Recompilar (WSL / Linux)

```bash
# Provas formais OmniProof-v4 e validação independente lcert --check-source
lume prove omega_sovereign.src
lume certify omega_sovereign.src -o omega_sovereign.cert
lume verify-cert omega_sovereign.cert --check-source omega_sovereign.src

# Garantia binária pós-codegen e envelope 2oo2D clean-room RV32IM
lume tv --exec omega_compute_core.src
lume tv-rt
lume smt-check omega_compute_core.smt2
lume stack --json omega_compute_core.src
lume mcdc --exec omega_compute_core.src
lume safety-envelope omega_compute_core.src --split -o safety_bundle

# PKI X.509v3 Ed25519, entropia NIST SP 800-90B e módulos de superfície (.lume)
lume x509 --self-test
lume entropy
for mod in modules/*.lume; do lume check "$mod" && lume run "$mod"; done

# Ressintetizar OmegaSovereign_GUI.exe (50.176 B) e OmegaSovereign_P33.exe (50.208 B)
lume build omega_pe64_gui_synth.src -o omega_pe64_synth_elf
./omega_pe64_synth_elf
```
