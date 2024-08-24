#include "smbios.h"
#include "kstdio.h"
bool SmbiosChecksum(void* addr, uint64_t len);

static SMBIOS g_Smbios = {0};
const char* SmbiosGetStr(SMBIOS_HEADER* hdr, uint64_t entry);

void Sm32NextTable(SMBIOS_HEADER* hdr) {
    hdr = (SMBIOS_HEADER*)(uint64_t)hdr+hdr->len;
    hdr = (SMBIOS_HEADER*)(uint64_t)hdr+SmbiosStrlen(&hdr);

}

#define SMBIOS_TABLE_VERSION(maj, min) ( ((maj * 10)) + (min) )

bool SmbiosTableParser(SMBIOS_HEADER* hdr, uint16_t tblVersion) {
   // if (hdr->handle == UINT16_MAX) {
     //   return false;
    //}
  //  debugf("%p",hdr->handle);
    return true;

}

bool InitSMBIOS(struct limine_smbios_response* lsr, SMBIOS* smOut) {

    
    if (smOut == NULL) {
        return false;
    }
    
    if (lsr->entry_32 != NULL) {

        //todo ...
        if (!memcmp(lsr->entry_32, "_SM_", 4)) {
            SMBIOS32* sm32 = (SMBIOS32*)lsr->entry_32;
            if(!SmbiosChecksum(sm32, sm32->length)) {
                debugf("sm32 checksum fail\n");
                return false;
            }
            else {
                g_Smbios.sm32 = *sm32;
                g_Smbios.major = SMBIOS32_MAJOR;
                debugf("Found SM_ANCHOR:");
                for (int i = 0; i < 5; ++i) {
                    debugf(" %X", sm32->anchor[i]);
                }
                debugf("\n");
                *smOut = g_Smbios;
                
               // SMBIOS_HEADER *hdr = (SMBIOS_HEADER*)g_Smbios.sm32.tblAddr;

              
                return true;
            }
            
        }
        return false;
    }
    else if (lsr->entry_64 != NULL) {
        
        
        if (!memcmp(lsr->entry_64, SMBIOS64_ANCHOR, 5)) {
            SMBIOS64* sm64 = (SMBIOS64*)lsr->entry_64;
   
            if (!SmbiosChecksum(sm64, sm64->length)) {
                printf("sm64 checksum fail\n");
                return false;
            }
            g_Smbios.sm64 = *sm64;
            g_Smbios.major = SMBIOS64_MAJOR;
            debugf("Found SM_ANCHOR:");
            for (int i = 0; i < 5; ++i) {
                debugf(" %X", sm64->anchor[i]);
            }
            debugf("\n");

         

            *smOut = g_Smbios;
            
            
            

        

            return true;
        }
       
        return false;

    }
    else {
        return false;
    }
}

bool SmbiosChecksum(void* addr, uint64_t len) {
    uint8_t sum = 0;
    uint8_t* entryAddr = (uint8_t*)addr;
    for (uint64_t i = 0; i < len; ++i) {
        sum += entryAddr[i];
    }
    return sum == 0;

}

int GetSMBIOSTable(SMBIOS_TABLE_TYPES type, SMBIOS_TABLE* table) {
    if (table == NULL) {
        return 2;
    }
    bool found = false;

    //not tested but in theory if there are multiple tables
    //we keep track of searched in table->instances and look for only new tables
    uint16_t counter = 0;
    uint64_t i = 0;
    for (SMBIOS_HEADER* hdr = (SMBIOS_HEADER*)g_Smbios.sm64.tableAddr; hdr->type != SMBIOS_TBL_END; i++) {
        if (hdr->type == type) {
          // printf("found cpu sss\n");
        

           
                table->instances += 1;
                table->table = (void*)hdr;
                found = true;
            
            
            counter++;

        }

        //find string length in the table
        //the string could be appended by double null terminator
        const char *strtab = (char *)hdr + hdr->len;
		size_t i;
		for (i = 1; strtab[i - 1] != '\0' || strtab[i] != '\0'; i++)
			;

		size_t totalStr = hdr->len + i + 1;
		hdr = (SMBIOS_HEADER *)((char *)hdr + totalStr);
        
         
    }

    if (!found) {
        return 0;
    }

    return 1;
}

char* SmbiosParseStr(uint64_t* start, uint8_t len) {
    char* addr = (char*)start;
    for (int i = 0; i < (len-1); ++i) {
        addr += strlen(addr) + 1;
    }
    return addr;
}

/*
const char* SmbiosGetStr(SMBIOS_HEADER* hdr, uint64_t entry) {
    if (entry == 0) {
        return "<None>";

    }

    const char* str = (char*)hdr + hdr->len;
    while (--entry) {
        while (*str++ != '\0');
    }
    return str;
}
*/

size_t SmbiosStrlen(void* loc) {
    char* addr = (char*)loc;
    while (*addr != '\0' || *(addr+1) != '\0') {
        addr++;
    }
    size_t locEnd = (size_t)(addr+2) - (size_t)loc;
    return locEnd;
}
