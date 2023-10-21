#include "include/kstdio.h"

//mostly stolen code from now, i will write my own when i get the time
int strcmp(const char* s1, const char* s2)
{
    while(*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}
int strncmp( const char * s1, const char * s2, size_t n )
{
    while ( n && *s1 && ( *s1 == *s2 ) )
    {
        ++s1;
        ++s2;
        --n;
    }
    if ( n == 0 )
    {
        return 0;
    }
    else
    {
        return ( *(unsigned char *)s1 - *(unsigned char *)s2 );
    }
}

char* strncpy(char* destination, const char* source, size_t num)
{
    // return if no memory is allocated to the destination
    if (destination == NULL) {
        return NULL;
    }
 
    // take a pointer pointing to the beginning of the destination string
    char* ptr = destination;
 
    // copy first `num` characters of C-string pointed by source
    // into the array pointed by destination
    while (*source && num--)
    {
        *destination = *source;
        destination++;
        source++;
    }
 
    // null terminate destination string
    *destination = '\0';
 
    // the destination is returned by standard `strncpy()`
    return ptr;
}

void *memcpy(void *dest, const void *src, size_t n) {
    uint8_t *pdest = (uint8_t *)dest;
    const uint8_t *psrc = (const uint8_t *)src;

    for (size_t i = 0; i < n; i++) {
        pdest[i] = psrc[i];
    }

    return dest;
}

void *memset(void *s, int c, size_t n) {
    uint8_t *p = (uint8_t *)s;

    for (size_t i = 0; i < n; i++) {
        p[i] = (uint8_t)c;
    }

    return s;
}

void *memmove(void *dest, const void *src, size_t n) {
    uint8_t *pdest = (uint8_t *)dest;
    const uint8_t *psrc = (const uint8_t *)src;

    if (src > dest) {
        for (size_t i = 0; i < n; i++) {
            pdest[i] = psrc[i];
        }
    } else if (src < dest) {
        for (size_t i = n; i > 0; i--) {
            pdest[i-1] = psrc[i-1];
        }
    }

    return dest;
}

int memcmp(const void *s1, const void *s2, size_t n) {
    const uint8_t *p1 = (const uint8_t *)s1;
    const uint8_t *p2 = (const uint8_t *)s2;

    for (size_t i = 0; i < n; i++) {
        if (p1[i] != p2[i]) {
            return p1[i] < p2[i] ? -1 : 1;
        }
    }

    return 0;
}

// Our quick and dirty strlen() implementation.
size_t strlen(const char *str) {
    size_t ret = 0;
    while (*str++) {
        ret++;
    }
    return ret;
}

char* strncat(char* destination, const char* source, size_t num)
{
    // make `ptr` point to the end of the destination string
    char* ptr = destination + strlen(destination);
 
    // Appends characters of the source to the destination string
    while (*source != '\0' && num--) {
        *ptr++ = *source++;
    }
 
    // null terminate destination string
    *ptr = '\0';
 
    // destination string is returned by standard `strncat()`
    return destination;
}

char* itoa(int value, char* result, int base) {
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
  
    // Reverse the string
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}
#include "dev/fbdev.h"
#include <stdarg.h>
#include <stdbool.h>
#define DEBUG_MAX_SIZE_MSG 512

#define COMMON_PUTS(str, stream) \
    do { \
        Fb_SwitchStream(FBDEV_DEFAULT, stream); \
        puts(str); \
        Fb_SwitchStream(FBDEV_DEFAULT, FB_OUTPUT_RESET); \
    } while (0)


#define COMMON_PRINTF(fmt, stream, ...) \
     do { \
        char buffer[DEBUG_MAX_SIZE_MSG]; \
        Fb_SwitchStream(FBDEV_DEFAULT, stream); \
        vsnprintf(buffer, DEBUG_MAX_SIZE_MSG, fmt, __VA_ARGS__); \
        printf("%s", buffer); \
        Fb_SwitchStream(FBDEV_DEFAULT, FB_OUTPUT_RESET); \
    } while (0)

#define COMMON_PUTC(c, stream) \
    do { \
        Fb_SwitchStream(FBDEV_DEFAULT, stream); \
        FbPutChar(c); \
        Fb_SwitchStream(FBDEV_DEFAULT, FB_OUTPUT_RESET); \
    }while (0);


void debugf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    COMMON_PRINTF(format, FB_OUTPUT_DBG_E9, args);
    va_end(args);
    
 

    

}
void BroadcastPrintf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    COMMON_PRINTF(format, FB_OUTPUT_BROADCAST, args);
    va_end(args);
}
void BroadcastPuts(const char* str) {
    COMMON_PUTS(str, FB_OUTPUT_BROADCAST);
}

void BroadcastPutc(char c) {
    COMMON_PUTC(c, FB_OUTPUT_BROADCAST);
}


void debugs(const char* str) {
    COMMON_PUTS(str, FB_OUTPUT_DBG_E9);
}

void putchar(char c) {
    COMMON_PUTC(c, FB_OUTPUT_STDIO);
}


int toupper(int ch) {
    if (ch >= 'a' && ch <= 'z') {
        // If the character is lowercase, convert it to uppercase
        return ch - 'a' + 'A';
    } else {
        // Otherwise, return the character unchanged
        return ch;
    }
}

void clrscr() {
    ClearFbScreen(FBDEV_DEFAULT);
}