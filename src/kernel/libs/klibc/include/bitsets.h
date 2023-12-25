#pragma once
#include <stdint.h>
#include <stdbool.h>
#define SET_MASK(x, y) (x |= (y))
#define UNSET_MASK(x, y) (x &= ~(y))

#define FLIP_MASK(x, y) (x ^= (y))

#define CHECK_MASK (x, y) (x & y)


#define __LOEXT(x, y, b) ((uint ## b ## _t)(x) & (y))
#define _HIEXT(x, y, b) ((uint ## b ## _t)((x) >> (8 * sizeof(x) - (b))) & (y))

#define LOBYTE(x) __LOEXT(x, 0xFF, 8)
#define HIBYTE(x) __HIEXT(x, 0xFF, 8)

#define LOWORD(x) __LOEXT(x, 0xFFFF, 16)
#define HIWORD(x) __HIEXT(x, 0xFFFF, 16)

#define LODWORD(x) __LOEXT(x, 0xFFFFFFFF, 32)
#define HIDWORD(x) __HIEXT(x, 0xFFFFFFFF, 32)



bool IsValidFlag(uint32_t flag);