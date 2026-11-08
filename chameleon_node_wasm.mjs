// ==========================================================================
// chameleon_node_wasm.mjs — Node.js N-API & WebAssembly Shared Memory Bridge
// Enforces [I0003] Linear Memory Bounds & Promoting unverified[T] -> verified[T]
// ==========================================================================

export function lumeChameleonVerifyWasmSlice(offset, byteLen, wasmLinearBytes) {
    if (offset < 0 || byteLen < 0 || offset + byteLen > wasmLinearBytes) {
        return { verified: 0, clampedLen: Math.max(0, wasmLinearBytes - Math.max(0, offset)) };
    }
    return { verified: 1, clampedLen: byteLen };
}

export function lumeChameleonPromoteInt(ptrOk, rawVal, loBound, hiBound) {
    if (!ptrOk || rawVal < loBound) return loBound;
    if (rawVal > hiBound) return hiBound;
    return rawVal;
}
