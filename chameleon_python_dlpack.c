/* ==========================================================================
 * chameleon_python_dlpack.c — Python 3.12 C-API + DLPack Zero-Copy Bridge
 * Zero-Copy Tensor Sharing (CPU/CUDA/Vulkan) under [I0003] QF_LIA Guard
 * ========================================================================== */
#include <stdint.h>
#include <stddef.h>

typedef struct {
    void* data;
    int32_t device_type;
    int32_t ndim;
    int64_t numel;
    int64_t elem_bytes;
} LumeDLManagedTensor;

int64_t lume_python_dlpack_verify_and_bytes(const LumeDLManagedTensor* t, int64_t max_bytes) {
    if (!t || !t->data || t->numel <= 0 || t->elem_bytes <= 0) return 0;
    int64_t total = t->numel * t->elem_bytes;
    return (total <= max_bytes) ? total : max_bytes;
}
