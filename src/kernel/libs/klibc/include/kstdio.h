#pragma once
#include <stdint.h>
#include <stddef.h>
#include <tinyprintf.h>
int strcmp(const char* s1, const char* s2);
char* strncpy(char* destination, const char* source, size_t num);

void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
void *memmove(void *dest, const void *src, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
size_t strlen(const char *str);
char* strncat(char* destination, const char* source, size_t num);




char* itoa(int value, char* result, int base);
