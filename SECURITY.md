# Security Policy — `omega-sovereign`

## Verified Security Guarantees

1. **`[V0001]` Compile-Time `QF_LIA` Verification:** All financial, telemetry, and buffer bounds are proven statically before binary emission.
2. **`[I0003]` Fail-Closed Chameleon FFI Boundaries:** External payloads (`unverified[T]`) cannot enter core logic without passing explicit refinement contracts.
3. **`P33` Anti-REA Binary Protection:** `OmegaSovereign_P33.exe` encrypts `.data` on disk (`XOR k=178`) with an MBA self-healing prologue.

## Reporting Vulnerabilities

Report security issues via **[OmegaSoftDLL/Lume Security Advisories](https://github.com/OmegaSoftDLL/Lume/security/advisories)**.
