#pragma once

#include <cstdint>

#if defined __ARM_FP16_FORMAT_IEEE && !defined __CUDACC__
#define CIL_FP16_TYPE 1
#else
#define CIL_FP16_TYPE 0
#endif

namespace cil {

union CIL16suf {
  int16_t i;
  uint16_t u;
#if CIL_FP16_TYPE
  __fp16 h;
#endif
  struct _fp16Format {
    unsigned int significand : 10;
    unsigned int exponent : 5;
    unsigned int sign : 1;
  } fmt;
};

union CIL32suf {
  int32_t i;
  uint32_t u;
  float f;
  struct _fp32Format {
    unsigned int significand : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } fmt;
};

union CIL64suf {
  int64_t i;
  uint64_t u;
  double f;
};

}  // namespace cil
