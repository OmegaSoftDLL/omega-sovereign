OPENQASM 3.0;
// ==========================================================================
// omega_quantum_bell.qasm — Lume Verified OpenQASM 3.0 Quantum Synthesizer
// Proven: quantum_circuit_depth_law (depth=5) & Qubit Bounds [0..1]
// State: |Phi+> = (|00> + e^(i*pi/4)|11>) / sqrt(2)
// ==========================================================================
include "stdgates.inc";
qubit[2] q;
bit[2] c;

reset q;
h q[0];
cx q[0], q[1];
rz(pi / 4) q[1];
c[0] = measure q[0];
c[1] = measure q[1];
