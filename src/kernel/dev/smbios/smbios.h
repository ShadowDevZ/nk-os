#pragma once
#include "limine.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "sysdefs.h"


#define SMBIOS32_ANCHOR "_SM_"
#define SMBIOS64_ANCHOR "_SM3_"

typedef struct {
    byte_t anchor[4]; // _SM_
    byte_t checksum;
    byte_t length;

    byte_t verMajor;
    byte_t verMinor;

    word_t maxSize;
    byte_t revision;
    byte_t formattedArea[5];

    byte_t interAnchor[5]; //_DMI_
    byte_t interChecksum;
    word_t tblLen;
    dword_t tblAddr;
    word_t tblCount;

    byte_t bcdRevision;



}PACKED SMBIOS32;


typedef struct {
    byte_t anchor[5];
	uint8_t checksum;
	uint8_t length;
	uint8_t verMajor;
	uint8_t verMinor;
	uint8_t docRev;
	uint8_t revision;
	uint8_t _reserved;
	uint32_t tableMax;
	uint64_t* tableAddr;


}PACKED SMBIOS64;

typedef struct {
    byte_t type; //0-127 smbios table types, 128-255 oem dependent
    byte_t len;
    word_t handle;

} PACKED SMBIOS_HEADER;

#define SMBIOS64_MAJOR (uchar_t)3
#define SMBIOS32_MAJOR (uchar_t)2

typedef struct {
    union {
     //   SMBIOS32 sm32;
        SMBIOS64 sm64;
        
    };
    //determines whether to use the sm32 or sm64
    //this field has value of SMBIOS64_MAJOR or SMBIO32_MAJOR
    uint8_t major;


}PACKED SMBIOS;


typedef enum {
    SMBIOS_TBL_BIOS = 0,

    SMBIOS_TBL_SYSTEM = 1,

    SMBIOS_TBL_ENCLOSURE = 3,

    SMBIOS_TBL_CPU = 4,

    SMBIOS_TBL_CACHE = 7,

    SMBIOS_TBL_SYSSLOTS = 9,

    SMBIOS_TBL_PHYSMEM = 16,

    SMBIOS_TBL_MEMDEV = 17, 

    SMBIOS_TBL_MEMMAPPED = 19,

    SMBIOS_TBL_BOOT = 32,

    SMBIOS_TBL_END = 127



}SMBIOS_TABLE_TYPES;

#include "tables/smbios_cpu.h"


typedef struct {
    SMBIOS_HEADER hdr;
    void* table;
    uint16_t instances; 

}PACKED SMBIOS_TABLE;

bool InitSMBIOS(struct limine_smbios_response* lsr, SMBIOS* smOut);
int GetSMBIOSTable(SMBIOS_TABLE_TYPES type, SMBIOS_TABLE* table);

const char* SmbiosGetStr(SMBIOS_HEADER* hdr, uint64_t entry) ;
SMBIOS GetSMBIOS();

bool SMBIOSAvailable();