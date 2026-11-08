<h1>
  <img src="https://raw.githubusercontent.com/OmegaSoftDLL/omega-sovereign/main/docs/assets/omega-sovereign-badge.svg" alt="Omega Sovereign" width="76" height="76" align="left" />
  Local Multimodal LLM Router &amp; Silicon Kernels
</h1>
<br clear="left"/>

## 1. Local Multimodal AI Router (`Ollama`)

Omega Sovereign orchestrates local multimodal inference on workstation hardware via `Ollama`:
- **`Gemma 4 E2B`:** Fast edge reasoning, structured JSON extraction, and contract synthesis.
- **`Ministral 3 3B`:** Low-latency code completion, bilingual (`EN`/`PT-BR`) technical synthesis, and telemetry summarization.

## 2. Multi-Target GPU &amp; FPGA Kernels (`omega_compute_core.src`)

| Artifact | Target | Description |
| :--- | :--- | :--- |
| `omega_ai_kernel.ptx` | `nvptx64` | NVIDIA CUDA PTX 8.0 (`sm_80`) kernel |
| `omega_ai_kernel.spvasm` | `spirv64` | Khronos Vulkan / OpenCL SPIR-V 1.6 compute shader |
| `omega_silicon.v` | `verilog-rtl` | Synthesizable IEEE 1364-2005 Verilog RTL hardware pipeline |
| `omega_rtc.kernel` | `baremetal` | Real-time bare-metal kernel (`[K0005]` DMA `W^X` + `[K0006]` stack guard) |
