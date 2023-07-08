include config/config.mk

.PHONY: all kernel clean run

_OBJS= boot.c.o framebuffer.c.o
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS))


all: kernel


run: $(KERNEL_NAME).iso
	@qemu-system-$(HOST_ARCH) -M q35 -m $(EMULATOR_MEM) -cdrom $(BUILD_DIR)/iso/$(KERNEL_NAME).iso -boot d


kernel: $(OBJ) $(CFG_DIR)/linker.ld
#	@$(LD) -n $(OBJ) $(LDFLAGS) -T $(CFG_DIR)/linker.ld -o $(BUILD_DIR)/$(KERNEL_FILE)
	@$(CC) -T $(CFG_DIR)/linker.ld -o $(BUILD_DIR)/$(KERNEL_FILE) $(LDFLAGS) $(OBJ)
	@echo -e ' ' LD $(KERNEL_FILE)

$(OBJ_DIR)/%.c.o: $(KRNL_DIR)/%.c 
	@$(CC) -MD -c $< -o $@ $(CFLAGS)
	@echo -e CC ' ' $@

$(OBJ_DIR)/%.c.o: $(SRC_DIR)/kernel/dev/%.c
	@$(CC) -MD -c $< -o $@ $(CFLAGS)
	@echo -e CC ' ' $@

$(OBJ_DIR)/%.asm.o: $(KRNL_DIR)/%.asm
	@$(AS) $(ASFLAGS) $< -o $@
	@echo -e AS ' ' $@

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

clean:
	@rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d $(BUILD_DIR)/*.iso $(BUILD_DIR)/*.elf