#pragma once

#define ROUND_UP(a, b) (((a) + (b) - 1) / (b))
#define ROUND_DOWN(a,b) ((a) / (b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a, b) (((a)>(b))?(a):(b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define SQUARE(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
#define SWAP(a, b) \
 do { (a) ^= (b); \
 (b) ^= (a); \
 (a) ^= (b); \
 } while (0)
#define CLOSEST_MULTIP_UP(a, b) ( (ROUND_UP((a),(b))) * (b) )
#define CLOSEST_MULTIP_DOWN(a, b) ((((a) / (b))) * (b))