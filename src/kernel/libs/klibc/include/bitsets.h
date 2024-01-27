#pragma once
#include <stdint.h>
#include <stdbool.h>
#define SET_MASK(x, y) (((x) |= (y)))


#define UNSET_MASK(x, y) (((x) &= ~(y)))

#define FLIP_MASK(x, y) (((x) ^= (y)))

#define CHECK_MASK(x, y) (((x) & (y)))

#define CHECK_BIT(x,y) ((x) & (1<<(y)))

//retrieves series of bits B, going in reverse by P bits and returning N bits (included)
#define BIT_INTERVAL(b,p,n) ((b) >> (p)) & ((1 << (n)) -1)

//determines if bit Y inside X is set
//index starts at 0
#define IS_SET(x, y) ( ( (x)  >> (y)  ) & 1 )  


//probably a terrible desicion, todo fix the function
//so it wont interfere instead of relyring on compiler specific functions
#ifdef uint
#pragma push_macro("uint")
#undef uint
#endif

#define __LOEXT(x, y, b) ((uint ## b ## _t)(x) & (y))
#define __HIEXT(x, y, b) ((uint ## b ## _t)((x) >> (8 * sizeof(x) - (b))) & (y))

#ifdef uint
#pragma pop_macro("uint")
#endif





#define LOBYTE(x) __LOEXT(x, 0xFF, 8)
#define HIBYTE(x) __HIEXT(x, 0xFF, 8)

#define LOWORD(x) __LOEXT(x, 0xFFFF, 16)
#define HIWORD(x) __HIEXT(x, 0xFFFF, 16)

#define LODWORD(x) __LOEXT(x, 0xFFFFFFFF, 32)
#define HIDWORD(x) __HIEXT(x, 0xFFFFFFFF, 32)

#define IsPowerOf2(x) (IsValidFlag(x))

bool IsValidFlag(uint64_t flag);