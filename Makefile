include config/config.mk

.PHONY: all kernel clean run iso limine distclean ksyms asmdump debug

override _C_SOURCES := $(abspath $(shell find -P src -type f -name '*.c'))
override _AS_SOURCES := $(abspath $(shell find -P src -type f -name '*.asm'))





C_SOURCES := $(filter $(addprefix %/,$(SOURCES_BUILD)),$(_C_SOURCES))
AS_SOURCES := $(filter $(addprefix %/,$(SOURCES_BUILD)),$(_AS_SOURCES))

OBJ := $(addprefix $(OBJ_DIR), $(notdir $(C_SOURCES:.c=.c.o)))
OBJASM := $(addprefix $(OBJ_DIR), $(notdir $(AS_SOURCES:.asm=.asm.o)))

dirs := $(dir $(C_SOURCES))
VPATH := $(dirs)





COLOR_RESET := '\033[0m'
COLOR_BLACK := '\033[0;30m'
COLOR_RED := '\033[0;31m'
COLOR_GREEN := '\033[0;32m'
COLOR_YELLOW := '\033[0;33m'
COLOR_BLUE := '\033[0;34m'
COLOR_MAGENTA := '\033[0;35m'
COLOR_CYAN := '\033[0;36m'
COLOR_WHITE := '\033[0;37m'
COLOR_BOLD := '\033[1m'
COLOR_UNDERLINE := '\033[4m'







all: kernel
#	@echo $(AS_SOURCES)

debug: kernel asmdump ksyms
	@echo -e $(COLOR_GREEN)[DBG]$(COLOR_RESET) Debug files were generated

_run: $(KERNEL_NAME).iso 
	@qemu-system-$(HOST_ARCH) -M q35 -m $(EMULATOR_MEM) -cdrom $(BUILD_DIR)/$(KERNEL_NAME).iso -boot d -d int -D ~/qemu.log
	@echo -e $(COLOR_GREEN)[QEMU]$(COLOR_RESET) $(BUILD_DIR)/$(KERNEL_FILE) RUNNING $(KERNEL_NAME).iso


run: _run 

kernel: $(OBJ) $(OBJASM) $(CFG_DIR)/linker.ld 
	
	

#	@$(LD) -n $(OBJ) $(LDFLAGS) -T $(CFG_DIR)/linker.ld -o $(BUILD_DIR)/$(KERNEL_FILE)
	
	@$(TARGET_CC) -T $(CFG_DIR)/linker.ld -o $(BUILD_DIR)/$(KERNEL_FILE) $(TARGET_LDFLAGS) $(OBJ) $(OBJASM)
	
	@echo -e LD ' ' $(KERNEL_FILE)
	@echo -e $(COLOR_GREEN)[BUILD]$(COLOR_RESET) $(BUILD_DIR)/$(KERNEL_FILE) SUCCESSFUL

$(OBJ): $(OBJ_DIR)%.c.o: %.c
	
	@$(TARGET_CC) -MD -c $< -o $@ $(TARGET_CFLAGS)
	@echo -e CC ' ' $@


$(OBJASM): $(OBJ_DIR)%.asm.o: %.asm
	@echo $(OBJASM)
	
	@$(TARGET_AS) $(TARGET_ASFLAGS) -o $@ $<
	@echo -e AS ' ' $@


iso: $(KERNEL_NAME).iso

distclean: clean
	rm -rf src/libs/boot/limine


asmdump: kernel
	@echo -e "; ***THIS ASMDUMP HAS BEEN AUTOGENERATED BY THE MAKEFILE***\n;SYNTAX: intel\n;ISA: x86_64\n;ENTRY_POINT: _start\n;KERNEL_MAIN: kmain\n" > $(SYM_DIR)/$(KERNEL_NAME).asmdump
	@objdump -C -d -mi386:x86-64:intel $(BUILD_DIR)/$(KERNEL_FILE) >> $(SYM_DIR)/$(KERNEL_NAME).asmdump
	@echo -e OD' ' $(KERNEL_NAME).asmdump



ksyms: kernel
	@nm -C $(BUILD_DIR)/$(KERNEL_FILE) --numeric-sort | grep -i -F " T " > $(SYM_DIR)/$(KERNEL_NAME).ksymx
#	awk {'print $$1 "\t" $$3'} $(SYM_DIR)/$(KERNEL_FILE).ksym > $(SYM_DIR)/$(KERNEL_FILE).ksym
	@awk {'print "0x" toupper($$1) "\t" $$3'} $(SYM_DIR)/$(KERNEL_NAME).ksymx | tee $(SYM_DIR)/$(KERNEL_NAME).ksym > /dev/null 2>&1
	@rm $(SYM_DIR)/$(KERNEL_NAME).ksymx
	@echo -e NM ' ' $(KERNEL_NAME).ksym





limine:	
	git clone https://github.com/limine-bootloader/limine.git --branch=v4.x-branch-binary --depth=1 $(LIMINE_BOOT_DIR)
#	$(MAKE) -C limine CC=gcc CFLAGS="-Wall -Wextra"
	$(MAKE) -C $(LIMINE_BOOT_DIR)
	@echo -e $(COLOR_GREEN)[DEP]$(COLOR_RESET) Successfully built Limine bootloader dependency


$(KERNEL_NAME).iso: kernel
	@rm -rf $(BUILD_DIR)/iso
	@mkdir -p $(BUILD_DIR)/iso
	
	@cp $(BUILD_DIR)/$(KERNEL_FILE) $(CFG_DIR)/limine.cfg $(LIMINE_BOOT_DIR)/limine-cd.bin \
	$(LIMINE_BOOT_DIR)/limine.sys $(BUILD_DIR)/iso/

	@xorriso -as mkisofs -b limine-cd.bin -no-emul-boot -boot-load-size 4 -boot-info-table \
	--protective-msdos-label $(BUILD_DIR)/iso -o $(BUILD_DIR)/iso/$(KERNEL_NAME).iso

	@$(LIMINE_BOOT_DIR)/limine-deploy $(BUILD_DIR)/iso/$(KERNEL_NAME).iso
	@cp $(BUILD_DIR)/iso/$(KERNEL_NAME).iso $(BUILD_DIR)
#	@/$(LIMINE_BOOT_DIR)/limine bios-install $(BUILD_DIR)/iso/$(KERNEL_NAME).iso
	@rm -rf $(BUILD_DIR)/iso/*
	@echo -e $(COLOR_GREEN)[ISO]$(COLOR_RESET) KERNEL IMAGE GENERATED $(BUILD_DIR)/nkos.iso
clean:
	@rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d $(BUILD_DIR)/*.iso $(BUILD_DIR)/*.elf $(SYM_DIR)/*
