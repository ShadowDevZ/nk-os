export HOST_ARCH=x86_64
export KERNEL_NAME=nkos
export TARGET_AR=$(PWD)/toolchain/$(HOST)/bin/$(HOST)-ar

export TARGET_AS=/bin/nasm 
export TARGET_CC=$(PWD)/toolchain/$(HOST)/bin/$(HOST)-gcc
export TARGET_LD=$(PWD)/toolchain/$(HOST)/bin/$(HOST)-ld
export TARGET_GAS=$(PWD)/toolchain/$(HOST)/bin/$(HOST)-as



export TARGET_LDFLAGS=-nostdlib -static -lgcc -z max-page-size=0x1000 -Wl,-Map,$(SYM_DIR)/$(KERNEL_NAME).map



###DEFINE HERE
SOURCES_BUILD := boot.c kver.c kstdio.c fbdev.c tinyprintf.c crti.asm crtn.asm
###DEFINE HERE


export C_VERSION=gnu11

export INCDIRS=-Isrc/kernel/include -Isrc/kernel/include/limine -Isrc/kernel/libs/klibc/include -Isrc/kernel/arch/$(HOST_ARCH)

export TARGET_CFLAGS=-g -ffreestanding -O2 -Wno-unused-local-typedefs -Wall \
 -Wextra -std=$(C_VERSION) -Wno-unused-variable -Wno-unused-label -Wno-unused-parameter \
 $(INCDIRS) -fno-stack-protector -fno-stack-check -fno-lto -fno-PIE -fno-PIC -m64 \
 -march=x86-64 -mabi=sysv -mno-80387 -mno-mmx -mno-sse -mno-sse2 -mno-red-zone -mcmodel=kernel \
 -Wunknown-pragmas


export HOST_CC=gcc

export TARGET_ASFLAGS=-Wall -felf64 -g
export HOST=$(HOST_ARCH)-elf
export INCLUDE_DIR=$(abspath src/kernel/include)
export ARCH_DIR=$(abspath src/kernel/$(HOST_ARCH))
export SRC_DIR=$(abspath src)
export BUILD_DIR=$(abspath build)
export KRNL_DIR=$(abspath src/kernel/$(KERNEL_NAME))
export RES_DIR=$(abspath src/kernel/libs/res)
export FONT_DIR=$(RES_DIR)/fonts
#even tho i think that variables shouldnt contain slash at the end. I havent found any other way to do it
#$(OBJ): $(OBJ_DIR)/%.o: %.c <- Doing this leads to no input file errors. 
export OBJ_DIR=$(BUILD_DIR)/objs/
export CFG_DIR=$(abspath config)
export SYM_DIR=$(BUILD_DIR)/sym

export LIBS_DIR=$(abspath src/libs)
export LIMINE_BOOT_DIR=$(LIBS_DIR)/boot/limine

export KERNEL_FILE=$(KERNEL_NAME).elf

export DEFAULT_FONT=zap-light16.psf

export EMULATOR_MEM=2G