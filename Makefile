include config/config.mk

.PHONY: all kernel clean run iso

override _C_SOURCES := $(abspath $(shell find -P src/kernel -type f -name '*.c'))




###DEFINE HERE
SOURCES_BUILD := boot.c kernel.c framebuffer.c
###DEFINE HERE

C_SOURCES := $(filter $(addprefix %/,$(SOURCES_BUILD)),$(_C_SOURCES))

OBJ := $(addprefix $(OBJ_DIR), $(notdir $(C_SOURCES:.c=.c.o)))
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


run: $(KERNEL_NAME).iso
	@qemu-system-$(HOST_ARCH) -M q35 -m $(EMULATOR_MEM) -cdrom $(BUILD_DIR)/iso/$(KERNEL_NAME).iso -boot d
	@echo -e $(COLOR_GREEN)[QEMU]$(COLOR_RESET) $(BUILD_DIR)/$(KERNEL_FILE) RUNNING $(KERNEL_NAME).iso


kernel: $(OBJ) $(CFG_DIR)/linker.ld
	

#	@$(LD) -n $(OBJ) $(LDFLAGS) -T $(CFG_DIR)/linker.ld -o $(BUILD_DIR)/$(KERNEL_FILE)
	
	@$(CC) -T $(CFG_DIR)/linker.ld -o $(BUILD_DIR)/$(KERNEL_FILE) $(LDFLAGS) $(OBJ)
	
	@echo -e LD ' ' $(KERNEL_FILE)
	@echo -e $(COLOR_GREEN)[BUILD]$(COLOR_RESET) $(BUILD_DIR)/$(KERNEL_FILE) SUCCESSFUL

$(OBJ): $(OBJ_DIR)%.c.o: %.c
	
	@$(CC) -MD -c $< -o $@ $(CFLAGS)
	@echo -e CC ' ' $@

iso: $(KERNEL_NAME).iso

$(KERNEL_NAME).iso: kernel
	@rm -rf $(BUILD_DIR)/iso
	@mkdir -p $(BUILD_DIR)/iso
	@cp $(FONT_DIR)/$(DEFAULT_FONT) $(BUILD_DIR)/iso
	@cp $(BUILD_DIR)/$(KERNEL_FILE) $(CFG_DIR)/limine.cfg $(LIMINE_BOOT_DIR)/limine-bios.sys \
	$(LIMINE_BOOT_DIR)/limine-bios-cd.bin $(BUILD_DIR)/iso/

	@xorriso -as mkisofs -b limine-bios-cd.bin -no-emul-boot -boot-load-size 4 -boot-info-table \
	--protective-msdos-label $(BUILD_DIR)/iso -o $(BUILD_DIR)/iso/$(KERNEL_NAME).iso

	@/$(LIMINE_BOOT_DIR)/limine bios-install $(BUILD_DIR)/iso/$(KERNEL_NAME).iso
	@rm -rf $(BUILD_DIR)iso
	@echo -e $(COLOR_GREEN)[ISO]$(COLOR_RESET) KERNEL IMAGE GENERATED $(BUILD_DIR)/iso/nkos.iso
clean:
	@rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d $(BUILD_DIR)/*.iso $(BUILD_DIR)/*.elf