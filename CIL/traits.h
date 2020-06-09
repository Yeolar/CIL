#pragma once

#include "CIL/defs.h"

namespace cil {

template <typename _Tp>
class DataType {
 public:
  typedef _Tp value_type;
  typedef value_type work_type;
  typedef value_type channel_type;
  typedef value_type vec_type;
  enum {
    generic_type = 1,
    depth = -1,
    channels = 1,
    fmt = 0,
    type = CIL_MAKETYPE(depth, channels)    // b'111'
  };
};

template <>
class DataType<bool> {
 public:
  typedef bool value_type;
  typedef int work_type;
  typedef value_type channel_type;
  typedef value_type vec_type;
  enum {
    generic_type = 0,
    depth = CIL_8U,
    channels = 1,
    fmt = (int)'u',
    type = CIL_MAKETYPE(depth, channels)    // b'0'
  };
};

template <>
class DataType<uchar> {
 public:
  typedef uchar value_type;
  typedef int work_type;
  typedef value_type channel_type;
  typedef value_type vec_type;
  enum {
    generic_type = 0,
    depth = CIL_8U,
    channels = 1,
    fmt = (int)'u',
    type = CIL_MAKETYPE(depth, channels)    // b'0'
  };
};

template <>
class DataType<char> {
 public:
  typedef char value_type;
  typedef int work_type;
  typedef value_type channel_type;
  typedef value_type vec_type;
  enum {
    generic_type = 0,
    depth = CIL_8S,
    channels = 1,
    fmt = (int)'c',
    type = CIL_MAKETYPE(depth, channels)    // b'1'
  };
};

template <>
class DataType<ushort> {
 public:
  typedef ushort value_type;
  typedef int work_type;
  typedef value_type channel_type;
  typedef value_type vec_type;
  enum {
    generic_type = 0,
    depth = CIL_16U,
    channels = 1,
    fmt = (int)'w',
    type = CIL_MAKETYPE(depth, channels)    // b'10'
  };
};

template <>
class DataType<short> {
 public:
  typedef short value_type;
  typedef int work_type;
  typedef value_type channel_type;
  typedef value_type vec_type;
  enum {
    generic_type = 0,
    depth = CIL_16S,
    channels = 1,
    fmt = (int)'s',
    type = CIL_MAKETYPE(depth, channels)    // b'11'
  };
};

template <>
class DataType<int> {
 public:
  typedef int value_type;
  typedef value_type work_type;
  typedef value_type channel_type;
  typedef value_type vec_type;
  enum {
    generic_type = 0,
    depth = CIL_32S,
    channels = 1,
    fmt = (int)'i',
    type = CIL_MAKETYPE(depth, channels)    // b'100'
  };
};

template <>
class DataType<float> {
 public:
  typedef float value_type;
  typedef value_type work_type;
  typedef value_type channel_type;
  typedef value_type vec_type;
  enum {
    generic_type = 0,
    depth = CIL_32F,
    channels = 1,
    fmt = (int)'f',
    type = CIL_MAKETYPE(depth, channels)    // b'101'
  };
};

template <>
class DataType<double> {
 public:
  typedef double value_type;
  typedef value_type work_type;
  typedef value_type channel_type;
  typedef value_type vec_type;
  enum {
    generic_type = 0,
    depth = CIL_64F,
    channels = 1,
    fmt = (int)'d',
    type = CIL_MAKETYPE(depth, channels)    // b'110'
  };
};

template <typename _Tp>
class DataDepth {
 public:
  enum { value = DataType<_Tp>::depth, fmt = DataType<_Tp>::fmt };
};

template <int _depth>
class TypeDepth {
  enum { depth = CIL_USRTYPE1 };
  typedef void value_type;
};

template <>
class TypeDepth<CIL_8U> {
  enum { depth = CIL_8U };
  typedef uchar value_type;
};

template <>
class TypeDepth<CIL_8S> {
  enum { depth = CIL_8S };
  typedef char value_type;
};

template <>
class TypeDepth<CIL_16U> {
  enum { depth = CIL_16U };
  typedef ushort value_type;
};

template <>
class TypeDepth<CIL_16S> {
  enum { depth = CIL_16S };
  typedef short value_type;
};

template <>
class TypeDepth<CIL_32S> {
  enum { depth = CIL_32S };
  typedef int value_type;
};

template <>
class TypeDepth<CIL_32F> {
  enum { depth = CIL_32F };
  typedef float value_type;
};

template <>
class TypeDepth<CIL_64F> {
  enum { depth = CIL_64F };
  typedef double value_type;
};

}  // namespace cil
