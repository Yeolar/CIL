#include "CIL/defs.h"
#include "CIL/range.h"

namespace cil {

class CIL_EXPORTS ParallelLoopBody {
 public:
  virtual ~ParallelLoopBody() {}
  virtual void operator()(const Range& range) const = 0;
};

CIL_EXPORTS void parallel_for_(const Range& range,
                               const ParallelLoopBody& body,
                               double nstripes = -1.);

} // namespace cil
