#include "CIL/alloc.h"
#include "CIL/error.h"
#include "CIL/util.h"

#define CIL_MALLOC_ALIGN 16

namespace cil {

void* fastMalloc(size_t size) {
  uchar* udata = (uchar*)malloc(size + sizeof(void*) + CIL_MALLOC_ALIGN);
  if (!udata) {
    CIL_ERROR("Failed to allocate %lu bytes", (unsigned long)size);
  }
  uchar** adata = alignPtr((uchar**)udata + 1, CIL_MALLOC_ALIGN);
  adata[-1] = udata;
  return adata;
}

void fastFree(void* ptr) {
  if (ptr) {
    uchar* udata = ((uchar**)ptr)[-1];
    assert(udata < (uchar*)ptr &&
           ((uchar*)ptr - udata) <=
              (ptrdiff_t)(sizeof(void*) + CIL_MALLOC_ALIGN));
    free(udata);
  }
}

}  // namespace cil
