#include <lib2.h>

namespace Lib2 {
static Init<0> init0 __attribute__((init_priority(101)));
static Init<2> init2 __attribute__((init_priority(103)));
}
