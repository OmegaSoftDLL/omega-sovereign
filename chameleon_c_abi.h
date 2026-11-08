/* ==========================================================================
 * chameleon_c_abi.h — Lume v1.1.0 Universal Chameleon C99/C++20 ABI Bridge
 * Boundary Contract: [I0003] unverified[int64_t] -> verified[int64_t]
 * ========================================================================== */
#ifndef LUME_CHAMELEON_C_ABI_H
#define LUME_CHAMELEON_C_ABI_H
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline int64_t lume_chameleon_guard_i64(int ptr_non_null, int64_t raw_val, int64_t lo_bound, int64_t hi_bound) {
    if (!ptr_non_null || raw_val < lo_bound) return lo_bound;
    if (raw_val > hi_bound) return hi_bound;
    return raw_val;
}

static inline int lume_chameleon_verify_slice(const void* ptr, size_t len, size_t cap) {
    return (ptr != NULL && len <= cap) ? 1 : 0;
}

#ifdef __cplusplus
}
#endif
#endif /* LUME_CHAMELEON_C_ABI_H */
