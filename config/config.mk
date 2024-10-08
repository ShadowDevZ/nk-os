#modify accordingly
export _BOOTSTRAP_MAKEOPTS=8
export _BOOTSTRAP_TC_INSTALL=$(PWD)/tc-in
export HOST_ARCH=x86_64
export KERNEL_NAME=nkos
export TARGET_AR=$(PWD)/toolchain/bin/$(HOST)-ar

export TARGET_AS=/bin/nasm 
export TARGET_CC=$(PWD)/toolchain/bin/$(HOST)-gcc
export TARGET_LD=$(PWD)/toolchain/bin/$(HOST)-ld
export TARGET_GAS=$(PWD)/toolchain/bin/$(HOST)-as
export TARGET_NM=$(PWD)/toolchain/bin/$(HOST)-nm
export TARGET_OBJDUMP=$(PWD)/toolchain/bin/$(HOST)-objdump
export TARGET_STRIP=$(PWD)/toolchain/bin/$(HOST)-strip

export TARGET_LDFLAGS=-nostdlib -static -lgcc -mno-red-zone -mcmodel=kernel -z max-page-size=0x1000 -Wl,-Map,$(SYM_DIR)/$(KERNEL_NAME).map


export NO_OPTIMIZE=fb.c.o flanterm.c.o
###DEFINE HERE
SOURCES_BUILD := boot.c kver.c kstdio.c fbdev.c printf.c crti.asm crtn.asm io.asm gdt.c idt.c \
isr.asm isr.c panic.c kernel.c ksyms.c gensym.c nkkerr.c pic.c irq.asm irq.c uptime.c keyboard.c \
kbctl.c bitsets.c pmm.c flanterm.c fb.c liballoc.c liballoc_fn.c smbios.c handlers.c pic.c mutex.c
#
###DEFINE HERE


export C_VERSION=gnu11

export INCDIRS=-Isrc/kernel/include -Isrc/kernel/include/limine -Isrc/kernel/libs/klibc/include -Isrc/kernel/arch/$(HOST_ARCH) \
-Isrc/kernel/include/sys -Isrc/kernel/arch/$(HOST_ARCH)/include -Isrc/kernel/dev/flanterm -Isrc/kernel/dev/smbios



export OPTIMIZATION_LEVEL=2


export TARGET_CFLAGS=-g -ffreestanding -Wno-unused-local-typedefs -Wall \
 -Wextra -std=$(C_VERSION) -Wno-unused-variable -Wno-unused-label -Wno-unused-parameter \
 $(INCDIRS) -fno-stack-protector -fno-stack-check -fno-lto -fno-PIE -fno-PIC -m64 \
 -march=x86-64 -mabi=sysv -mno-80387 -mno-red-zone -mcmodel=kernel \
 -Wunknown-pragmas -Wno-attributes 
#-mno-mmx -mno-sse -mno-sse2

export HOST_CC=gcc

export TARGET_ASFLAGS=-Wall -O$(OPTIMIZATION_LEVEL) -felf64 -g -isrc/kernel/arch/x86_64/include/ -wno-reloc-abs-dword -wno-reloc-abs-qword -wno-reloc-rel-dword



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
export LIMINE_INC_DIR=$(abspath src/kernel/include/limine)

export SYS_DIR=$(abspath src/kernel/sys)
export SCRIPTS_DIR=$(abspath scripts)

export KERNEL_FILE=$(KERNEL_NAME).elf

export DEFAULT_FONT=zap-light16.psf

export EMULATOR_MEM=1G
export EMULATOR_SMP=2