#pragma once
#include <stdint.h>
#include <stdbool.h>
#define SET_MASK(x, y) (x |= (y))
#define UNSET_MASK(x, y) (x &= ~(y))

#define FLIP_MASK(x, y) (x ^= (y))

#define CHECK_MASK (x, y) (x & y)

bool IsValidFlag(uint32_t flag);