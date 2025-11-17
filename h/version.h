// Version info

#include "build.h"

#if _PM != 0
#define VER_MAJOR 2
#define VER_MINOR 03
#define VER_REVISION "D"

#else
#define VER_MAJOR 5
#define VER_MINOR 00
// #define VER_REVISION ""   // Must be string with no spaces - leading dot optional
// #define VER_REVISION ".4-shl"   // Must be string with no spaces - leading dot optional
#define VER_REVISION ".0-gky"   // Must be string with no spaces - leading dot optional

#endif

