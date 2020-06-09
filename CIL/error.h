#pragma once

#include <cassert>
#include <cstdio>
#include <stdexcept>

namespace cil {

#if defined __GNUC__
#define CIL_Func __func__
#elif defined _MSC_VER
#define CIL_Func __FUNCTION__
#else
#define CIL_Func ""
#endif

#define CIL_ERROR(...)                    \
  do {                                    \
    char err_msg[2048];                   \
    snprintf(err_msg, 2048, __VA_ARGS__); \
    throw std::runtime_error(err_msg);    \
  } while(0)

#define CIL_ASSERT(expr)                                                    \
  if (!!(expr))                                                             \
    ;                                                                       \
  else                                                                      \
    CIL_ERROR("Assertion Failure: `%s` evaluated to false in `%s` (%s:%d)", \
              #expr, CIL_Func, __FILE__, __LINE__)

}  // namespace cil
