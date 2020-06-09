#pragma once

#include "CIL/mat/shared.h"

namespace cil {

void convertAndUnrollScalar(const Mat& sc,
                            int buftype,
                            uchar* scbuf,
                            size_t blocksize);

BinaryFunc getConvertFunc(int sdepth, int ddepth);

} // namespace cil
