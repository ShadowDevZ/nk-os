#pragma once

#define KERNEL_LOAD_OFFSET 0xffffffff80000000


#define ADDR_V2P(x) (x - KERNEL_LOAD_OFFSET)
#define ADDR_P2V(x) (x + KERNEL_LOAD_OFFSET)