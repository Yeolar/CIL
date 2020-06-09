#pragma once

#if defined __SSE2__ || defined _M_X64 || \
    (defined _M_IX86_FP && _M_IX86_FP >= 2)
#include <emmintrin.h>
#define CIL_MMX 1
#define CIL_SSE 1
#define CIL_SSE2 1
#if defined __SSE3__ || (defined _MSC_VER && _MSC_VER >= 1500)
#include <pmmintrin.h>
#define CIL_SSE3 1
#endif
#if defined __SSSE3__ || (defined _MSC_VER && _MSC_VER >= 1500)
#include <tmmintrin.h>
#define CIL_SSSE3 1
#endif
#if defined __SSE4_1__ || (defined _MSC_VER && _MSC_VER >= 1500)
#include <smmintrin.h>
#define CIL_SSE4_1 1
#endif
#if defined __SSE4_2__ || (defined _MSC_VER && _MSC_VER >= 1500)
#include <nmmintrin.h>
#define CIL_SSE4_2 1
#endif
#if defined __POPCNT__ || (defined _MSC_VER && _MSC_VER >= 1500)
#ifdef _MSC_VER
#include <nmmintrin.h>
#else
#include <popcntintrin.h>
#endif
#define CIL_POPCNT 1
#endif
#if defined __AVX__ || (defined _MSC_VER && _MSC_VER >= 1600 && 0)
// MS Visual Studio 2010 (2012?) has no macro pre-defined to identify the use of
// /arch:AVX
// See:
// http://connect.microsoft.com/VisualStudio/feedback/details/605858/arch-avx-should-define-a-predefined-macro-in-x64-and-set-a-unique-value-for-m-ix86-fp-in-win32
#include <immintrin.h>
#define CIL_AVX 1
#if defined(_XCR_XFEATURE_ENABLED_MASK)
#define __xgetbv() _xgetbv(_XCR_XFEATURE_ENABLED_MASK)
#else
#define __xgetbv() 0
#endif
#endif
#if defined __AVX2__ || (defined _MSC_VER && _MSC_VER >= 1800 && 0)
#include <immintrin.h>
#define CIL_AVX2 1
#if defined __FMA__
#define CIL_FMA3 1
#endif
#endif
#endif

#if (defined WIN32 || defined _WIN32) && defined(_M_ARM)
#include <Intrin.h>
#include <arm_neon.h>
#define CIL_NEON 1
#define CPU_HAS_NEON_FEATURE (true)
#elif defined(__ARM_NEON__) || (defined(__ARM_NEON) && defined(__aarch64__))
#include <arm_neon.h>
#define CIL_NEON 1
#endif

#if defined __GNUC__ && defined __arm__ &&             \
    (defined __ARM_PCS_VFP || defined __ARM_VFPV3__ || \
     defined __ARM_NEON__) &&                          \
    !defined __SOFTFP__
#define CIL_VFP 1
#endif

#ifndef CIL_MMX
#define CIL_MMX 0
#endif
#ifndef CIL_SSE
#define CIL_SSE 0
#endif
#ifndef CIL_SSE2
#define CIL_SSE2 0
#endif
#ifndef CIL_SSE3
#define CIL_SSE3 0
#endif
#ifndef CIL_SSSE3
#define CIL_SSSE3 0
#endif
#ifndef CIL_SSE4_1
#define CIL_SSE4_1 0
#endif
#ifndef CIL_SSE4_2
#define CIL_SSE4_2 0
#endif
#ifndef CIL_POPCNT
#define CIL_POPCNT 0
#endif
#ifndef CIL_AVX
#define CIL_AVX 0
#endif
#ifndef CIL_AVX2
#define CIL_AVX2 0
#endif
#ifndef CIL_FMA3
#define CIL_FMA3 0
#endif
#ifndef CIL_NEON
#define CIL_NEON 0
#endif
#ifndef CIL_VFP
#define CIL_VFP 0
#endif
