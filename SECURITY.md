# Security Policy — `omega-sovereign` (`v5.0`)

Omega Sovereign `v5.0` enforces defense-in-depth across compile-time formal contracts, post-codegen machine-code verification, constant-time cryptographic execution, polyglot FFI boundaries, and dual-channel runtime fault containment.

## Verified Security & Assurance Guarantees

1. **`OmniProof-v4` & `lcert --check-source` Source-Bound Verification (`[V0001]`, `[V0002]`, `[K0005]`, `[K0006]`):**
   All arithmetic, financial, layout, and buffer invariants—together with `@bound` WCET cycle budgets, `/ pure` isolation (`[E0200]`), and `@no_alloc` deterministic execution (`[E0210]`)—are proven statically before code generation and cryptographically bound to source SHA-256 digests and AST structure in `omega_sovereign.cert` and `omega_compute_core.cert`.
2. **`[C0011]` Source & `[C0010]` Machine Constant-Time Cryptography:**
   Secret-handling primitives (`@secret @no_alloc` in `modules/constant_time_crypto_x509.lume` and `omega_sovereign.src`) prohibit secret-dependent branches, memory indexing, and variable-latency instructions at compile time (`[C0011]`), lower conditional selection to branchless `cmov`, and are verified directly on emitted machine code by `lume tv` (`[C0010]`) and static stack analysis (`lume stack` `<= 536 B`).
3. **Strict Ed25519 X.509v3 PKI, NIST SP 800-90B Entropy & Authenticated TLS 1.3:**
   Enforces fail-closed DER/PEM X.509v3 certificate chain verification (`BasicConstraints`, `KeyUsage`, validity windows, signature integrity via `lume x509`), continuous NIST SP 800-90B Repetition Count and Adaptive Proportion OS entropy health checks (`lume entropy`), and RFC 8446 TLS 1.3 key-schedule and transcript authentication.
4. **`2oo2D` Clean-Room `RV32IM` Lockstep Safety Envelope (`safety_bundle/`):**
   Critical computations execute in dual-channel diverse lockstep comparing native `x86_64` Channel A against a clean-room `RV32IM` Channel B (`0` shared compiler functions with `lumec`). Any architectural or transient bit-flip divergence triggers an immediate fail-closed `SafeStateTrip`.
5. **`[I0003]` Fail-Closed Chameleon 9-Ecosystem FFI Boundaries:**
   External foreign buffers (`unverified[T]` across C/C++, Rust, Python DLPack, Node.js/WASM, Go, Java JNI, .NET, SQL, and OpenAPI) cannot enter verified Lume kernels without passing non-null, cache-line alignment, byte-length, and element-stride proofs (`modules/chameleon_polyglot_guard.lume`).
6. **`P33` Anti-Reverse-Engineering Binary Shield (`OmegaSovereign_P33.exe`):**
   `OmegaSovereign_P33.exe` (`50,208` bytes) encrypts active `.data` payloads at rest using `XOR k=178 (0xB2)`, executes a self-healing Mixed Boolean-Arithmetic (`MBA`) decryption prologue at entry (`0x401000`) and `WM_CREATE`, and seals binary integrity with a `32`-byte `LUME_SEAL` trailer.

## Reporting Vulnerabilities

Please report suspected vulnerabilities privately via **[OmegaSoftDLL/Lume Security Advisories](https://github.com/OmegaSoftDLL/Lume/security/advisories)**. Do not open public issues for undisclosed security findings.
