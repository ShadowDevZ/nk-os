#pragma once
#include <stdint.h>
#include <stddef.h>
#include "dev/fbdev.h"
#include <tinyprintf.h>
#include "include/io.h"
int strcmp(const char* s1, const char* s2);
char* strncpy(char* destination, const char* source, size_t num);
int strncmp( const char * s1, const char * s2, size_t n );
void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
void *memmove(void *dest, const void *src, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
size_t strlen(const char *str);
char* strncat(char* destination, const char* source, size_t num);

#define puts(str) _FbPutString(str);
#define debugc(c) x64_outb(0xE9, c);


char* itoa(int value, char* result, int base);
void debugf(const char* format, ...);
void debugs(const char* str);
void putchar(char c);

#define FLAG_SET(x, flag) x |= flag
#define FLAG_UNSET(x, flag) x &= ~(flag);



int toupper(int ch);