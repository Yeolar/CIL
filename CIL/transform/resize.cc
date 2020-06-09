#include "CIL/transform/resize.h"

#include <cfloat>
#include <cmath>
#include <cstring>

#include "CIL/mat/mat.h"
#include "CIL/auto_buffer.h"
#include "CIL/fast_math.h"
#include "CIL/hardware.h"
#include "CIL/parallel.h"
#include "CIL/saturate_cast.h"
#include "CIL/util.h"

namespace cil {
#include "CIL/transform/resize/interp.lut.h"
#include "CIL/transform/resize/common.h"
#include "CIL/transform/resize/nearest.h"
#include "CIL/transform/resize/linear.h"
#include "CIL/transform/resize/cubic.h"
#include "CIL/transform/resize/lanczos.h"
#include "CIL/transform/resize/area.h"
#include "CIL/transform/resize/invoker.h"
}
