#include "smbios.h"
#include "kstdio.h"
bool SmbiosChecksum(void* addr, uint64_t len);

static SMBIOS g_Smbios = {0};
const char* SmbiosGetStr(SMBIOS_HEADER* hdr, uint64_t entry);


bool InitSMBIOS(struct limine_smbios_response* lsr, SMBIOS* smOut) {

    
    if (smOut == NULL) {
        return false;
    }
    
    if (lsr->entry_32 != NULL) {

        //todo ...
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
