#pragma once
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <kattributes.h>
typedef unsigned char uchar_t;

typedef uchar_t byte_t;


typedef uint8_t u8_t;
typedef uint16_t u16_t;

typedef uint32_t u32_t;
typedef uint64_t u64_t;

typedef int8_t i8_t;
typedef int16_t i16_t;
typedef int32_t i32_t;
typedef int64_t i64_t;


typedef unsigned short ushort;
typedef unsigned int uint;
typedef uint16_t word_t;
typedef unsigned long dword_t;
typedef uint64_t qword_t;

typedef unsigned long ulong;
typedef unsigned long long ullong;

typedef uint32_t HEXCLR;

#define KERNEL_LOAD_ADDR 0xffffffff80000000

#include "limine.h"
#define UNUSED(x) (void)(x)