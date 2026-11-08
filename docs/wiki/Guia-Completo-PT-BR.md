<h1>
  <img src="https://raw.githubusercontent.com/OmegaSoftDLL/omega-sovereign/main/docs/assets/omega-sovereign-badge.svg" alt="Omega Sovereign" width="76" height="76" align="left" />
  Guia Completo do Omega Sovereign v1.1.0 (PT-BR)
</h1>
<br clear="left"/>

O **Omega Sovereign `v1.1.0`** e o Command Center Desktop Nativo Windows 64-bit (`OmegaSovereign_GUI.exe` e `OmegaSovereign_P33.exe`) e Estacao de Trabalho Multimodal de IA construida **100% em Lume `v1.1.0`**.

## Como Executar no Windows

```powershell
Start-Process .\OmegaSovereign_GUI.exe
```

## Como Recompilar no WSL / Linux

```bash
lume build omega_pe64_gui_synth.src -o omega_pe64_synth_elf
./omega_pe64_synth_elf
```
