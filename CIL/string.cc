#include "CIL/alloc.h"
#include "CIL/string.h"
#include "CIL/util.h"

namespace cil {

char* String::allocate(size_t len) {
  size_t totalsize = alignSize(len + 1, (int)sizeof(int));
  int* data = (int*)fastMalloc(totalsize + sizeof(int));
  data[0] = 1;
  cstr_ = (char*)(data + 1);
  len_ = len;
  cstr_[len] = 0;
  return cstr_;
}

void String::deallocate() {
  int* data = (int*)cstr_;
  len_ = 0;
  cstr_ = 0;

  if (data && 1 == CIL_XADD(data - 1, -1)) {
    fastFree(data - 1);
  }
}

} // namespace cil
