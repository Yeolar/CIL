#pragma once

#include "CIL/defs.h"
#include "CIL/string.h"
#include "CIL/io/options.h"
#include "CIL/mat/mat.h"

namespace cil {

CIL_EXPORTS Mat imread(const String& filename, int flags = IMREAD_COLOR);

CIL_EXPORTS bool imwrite(const String& filename,
                           InputArray img,
                           const std::vector<int>& params = std::vector<int>());

CIL_EXPORTS Mat imdecode(InputArray buf, int flags);

CIL_EXPORTS Mat imdecode(InputArray buf, int flags, Mat* dst);

CIL_EXPORTS bool imencode(
    const String& ext,
    InputArray img,
    std::vector<uchar>& buf,
    const std::vector<int>& params = std::vector<int>());

} // namespace cil
