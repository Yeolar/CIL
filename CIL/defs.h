#pragma once

#include <cstddef>
#include <cstdint>

#include "CIL/arch.h"

namespace cil {

// Type aliases
using uchar = unsigned char;
using ushort = unsigned short;

// CIL_EXPORTS
#if (defined WIN32 || defined _WIN32 || defined WINCE || \
     defined __CYGWIN__) &&                              \
    defined CILAPI_EXPORTS
#define CIL_EXPORTS __declspec(dllexport)
#elif defined __GNUC__ && __GNUC__ >= 4
#define CIL_EXPORTS __attribute__((visibility("default")))
#else
#define CIL_EXPORTS
#endif

#define CIL_CN_MAX 512
#define CIL_CN_SHIFT 3
#define CIL_DEPTH_MAX (1 << CIL_CN_SHIFT)

#define CIL_8U 0
#define CIL_8S 1
#define CIL_16U 2
#define CIL_16S 3
#define CIL_32S 4
#define CIL_32F 5
#define CIL_64F 6
#define CIL_USRTYPE1 7

#define CIL_MAT_DEPTH_MASK (CIL_DEPTH_MAX - 1)
#define CIL_MAT_DEPTH(flags) ((flags)&CIL_MAT_DEPTH_MASK)

#define CIL_MAKETYPE(depth, cn) \
  (CIL_MAT_DEPTH(depth) + (((cn)-1) << CIL_CN_SHIFT))
#define CIL_MAKE_TYPE CIL_MAKETYPE

#define CIL_8UC1 CIL_MAKETYPE(CIL_8U, 1)
#define CIL_8UC2 CIL_MAKETYPE(CIL_8U, 2)
#define CIL_8UC3 CIL_MAKETYPE(CIL_8U, 3)
#define CIL_8UC4 CIL_MAKETYPE(CIL_8U, 4)
#define CIL_8UC(n) CIL_MAKETYPE(CIL_8U, (n))

#define CIL_8SC1 CIL_MAKETYPE(CIL_8S, 1)
#define CIL_8SC2 CIL_MAKETYPE(CIL_8S, 2)
#define CIL_8SC3 CIL_MAKETYPE(CIL_8S, 3)
#define CIL_8SC4 CIL_MAKETYPE(CIL_8S, 4)
#define CIL_8SC(n) CIL_MAKETYPE(CIL_8S, (n))

#define CIL_16UC1 CIL_MAKETYPE(CIL_16U, 1)
#define CIL_16UC2 CIL_MAKETYPE(CIL_16U, 2)
#define CIL_16UC3 CIL_MAKETYPE(CIL_16U, 3)
#define CIL_16UC4 CIL_MAKETYPE(CIL_16U, 4)
#define CIL_16UC(n) CIL_MAKETYPE(CIL_16U, (n))

#define CIL_16SC1 CIL_MAKETYPE(CIL_16S, 1)
#define CIL_16SC2 CIL_MAKETYPE(CIL_16S, 2)
#define CIL_16SC3 CIL_MAKETYPE(CIL_16S, 3)
#define CIL_16SC4 CIL_MAKETYPE(CIL_16S, 4)
#define CIL_16SC(n) CIL_MAKETYPE(CIL_16S, (n))

#define CIL_32SC1 CIL_MAKETYPE(CIL_32S, 1)
#define CIL_32SC2 CIL_MAKETYPE(CIL_32S, 2)
#define CIL_32SC3 CIL_MAKETYPE(CIL_32S, 3)
#define CIL_32SC4 CIL_MAKETYPE(CIL_32S, 4)
#define CIL_32SC(n) CIL_MAKETYPE(CIL_32S, (n))

#define CIL_32FC1 CIL_MAKETYPE(CIL_32F, 1)
#define CIL_32FC2 CIL_MAKETYPE(CIL_32F, 2)
#define CIL_32FC3 CIL_MAKETYPE(CIL_32F, 3)
#define CIL_32FC4 CIL_MAKETYPE(CIL_32F, 4)
#define CIL_32FC(n) CIL_MAKETYPE(CIL_32F, (n))

#define CIL_64FC1 CIL_MAKETYPE(CIL_64F, 1)
#define CIL_64FC2 CIL_MAKETYPE(CIL_64F, 2)
#define CIL_64FC3 CIL_MAKETYPE(CIL_64F, 3)
#define CIL_64FC4 CIL_MAKETYPE(CIL_64F, 4)
#define CIL_64FC(n) CIL_MAKETYPE(CIL_64F, (n))

#define CIL_MAT_CN_MASK ((CIL_CN_MAX - 1) << CIL_CN_SHIFT)
#define CIL_MAT_CN(flags) \
  ((((flags)&CIL_MAT_CN_MASK) >> CIL_CN_SHIFT) + 1)
#define CIL_MAT_TYPE_MASK (CIL_DEPTH_MAX * CIL_CN_MAX - 1)
#define CIL_MAT_TYPE(flags) ((flags)&CIL_MAT_TYPE_MASK)
#define CIL_MAT_CONT_FLAG_SHIFT 14
#define CIL_MAT_CONT_FLAG (1 << CIL_MAT_CONT_FLAG_SHIFT)
#define CIL_IS_MAT_CONT(flags) ((flags)&CIL_MAT_CONT_FLAG)
#define CIL_IS_CONT_MAT CIL_IS_MAT_CONT
#define CIL_SUBMAT_FLAG_SHIFT 15
#define CIL_SUBMAT_FLAG (1 << CIL_SUBMAT_FLAG_SHIFT)

/** Size of each channel item,
   0x124489 = 1000 0100 0100 0010 0010 0001 0001 ~ array of
   sizeof(arr_type_elem) */
#define CIL_ELEM_SIZE1(type) \
  ((((sizeof(size_t) << 28) | 0x8442211) >> CIL_MAT_DEPTH(type) * 4) & 15)

/** 0x3a50 = 11 10 10 01 01 00 00 ~ array of log2(sizeof(arr_type_elem)) */
#define CIL_ELEM_SIZE(type)                                             \
  (CIL_MAT_CN(type) << ((((sizeof(size_t) / 4 + 1) * 16384 | 0x3a50) >> \
                           CIL_MAT_DEPTH(type) * 2) &                   \
                          3))

#define CIL_MAX_DIM 32
#define CIL_MAX_DIM_HEAP 1024

#define HAVE_PTHREADS

/* parallel_for with pthreads */
#define HAVE_PTHREADS_PF

// Mat forward declarations
class CIL_EXPORTS Mat;
typedef Mat MatND;
template <typename _Tp>
class Mat_;

} // namespace cil
