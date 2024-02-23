#pragma once

#define KERNEL_LOAD_OFFSET 0xffffffff80000000


extern volatile struct limine_hhdm_request hhdm_request;
#define KERNEL_OFFSET_HHDM (hhdm_request.response->offset)

typedef void* virtaddr_t;
typedef void* physaddr_t;

static inline virtaddr_t PmmPhys2Virt(physaddr_t pa) {
    if (pa == ((physaddr_t)0)) {
        return ((virtaddr_t)0);
    }
    return (virtaddr_t)((uint64_t*)pa + KERNEL_OFFSET_HHDM);
}

static inline physaddr_t PmmVirt2Phys(virtaddr_t va) {
    if (va == ((virtaddr_t)0)) {
        return ((physaddr_t)0);
    }
    return (physaddr_t)((uint64_t*)va - KERNEL_OFFSET_HHDM);
}
