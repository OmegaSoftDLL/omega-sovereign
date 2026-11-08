// ==========================================================================
// chameleon_rust_ffi.rs — Lume v1.1.0 Universal Chameleon Rust cdylib Bridge
// Panic-Free catch_unwind + Perceus Linear Zero-Copy Borrow Guard [I0003]
// ==========================================================================

#[repr(C)]
pub struct LumeVerifiedSlice {
    pub ptr_non_null: i64,
    pub byte_len: i64,
    pub max_cap: i64,
}

#[no_mangle]
pub extern "C" fn lume_rust_chameleon_promote(ptr_ok: i64, raw_val: i64, lo: i64, hi: i64) -> i64 {
    let res = std::panic::catch_unwind(|| {
        if ptr_ok == 0 || raw_val < lo { return lo; }
        if raw_val > hi { return hi; }
        raw_val
    });
    match res {
        Ok(v) => v,
        Err(_) => lo,
    }
}
