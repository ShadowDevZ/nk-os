include config/config.mk



.PHONY: all kernel clean run iso bootstrap debootstrap distclean ksyms asmdump debug run_dbg release toolchain first_setup

override _C_SOURCES := $(abspath $(shell find -P src -type f -name '*.c'))
override _AS_SOURCES := $(abspath $(shell find -P src -type f -name '*.asm'))





C_SOURCES := $(filter $(addprefix %/,$(SOURCES_BUILD)),$(_C_SOURCES))
AS_SOURCES := $(filter $(addprefix %/,$(SOURCES_BUILD)),$(_AS_SOURCES))

OBJ := $(addprefix $(OBJ_DIR), $(notdir $(C_SOURCES:.c=.c.o)))
OBJASM := $(addprefix $(OBJ_DIR), $(notdir $(AS_SOURCES:.asm=.asm.o)))

dirs := $(dir $(C_SOURCES))
dirs += $(dir $(AS_SOURCES))
VPATH := $(dirs)

LIMINE_BRANCH := v8.x-binary



all: kernel iso
	
	@echo $(COLOR_GREEN)COMPLETED$(COLOR_RESET)
#	@echo $(AS_SOURCES)

rerun: clean run
	@echo $(COLOR_GREEN)Cleanup completed$(COLOR_RESET)
	@echo $(COLOR_GREEN)COMPLETED$(COLOR_RESET)
#	@echo $(AS_SOURCES)


debug: kernel asmdump ksyms
	@echo $(COLOR_GREEN)[DBG]$(COLOR_RESET) Debug files were generated


_run : $(KERNEL_NAME).iso
	@echo $(COLOR_GREEN)[QEMU]$(COLOR_RESET) $(BUILD_DIR)/$(KERNEL_FILE) RUNNING $(KERNEL_NAME).iso
	@qemu-system-$(HOST_ARCH) -M q35 -m $(EMULATOR_MEM) -cdrom $(BUILD_DIR)/$(KERNEL_NAME).iso -boot d -debugcon stdio -smp $(EMULATOR_SMP)

vbox: $(KERNEL_NAME).iso 
	@echo $(COLOR_GREEN)[VBOX]$(COLOR_RESET) $(BUILD_DIR)/$(KERNEL_FILE) RUNNING $(KERNEL_NAME).iso
	@VBoxManage startvm NKOS
	

run_dbg:
	@echo -e $(COLOR_GREEN) [QEMU]$(COLOR_RESET) GDB Debugging session started on localhost:1234
	@qemu-system-$(HOST_ARCH) -M q35 -m $(EMULATOR_MEM) -s -S -serial stdio -cdrom $(BUILD_DIR)/$(KERNEL_NAME).iso -boot d

run: _run 

kernel: $(OBJ) $(OBJASM) $(CFG_DIR)/linker.ld 

	
	

	

#	@$(LD) -n $(OBJ) $(LDFLAGS) -T $(CFG_DIR)/linker.ld -o $(BUILD_DIR)/$(KERNEL_FILE)
#	

	
	@$(TARGET_CC) -T $(CFG_DIR)/linker.ld -o $(BUILD_DIR)/$(KERNEL_FILE) $(TARGET_LDFLAGS) $(OBJ) $(OBJASM)
	
	@echo LD ' ' $(KERNEL_FILE)
	@echo $(COLOR_GREEN)[BUILD]$(COLOR_RESET) $(BUILD_DIR)/$(KERNEL_FILE) SUCCESSFUL

$(OBJ): $(OBJ_DIR)%.c.o: %.c

ifneq ($(filter $($(notdir $(basename $@))),$(NO_OPTIMIZE)),)
		$(TARGET_CFLAGS) += $(OPTIMIZATION_LEVEL)
endif
	@$(TARGET_CC) -MD -c $< -o $@ $(TARGET_CFLAGS)



	@echo CC ' ' $(basename $(notdir $@))


$(OBJASM): $(OBJ_DIR)%.asm.o: %.asm

#	@echo $(OBJASM)
	
	@$(TARGET_AS) $(TARGET_ASFLAGS) -o $@ $<
	@echo AS ' ' $(basename $(notdir $@))


iso: $(KERNEL_NAME).iso

_dummyrelease: 
	@$(TARGET_STRIP) --strip-unneeded $(BUILD_DIR)/$(KERNEL_FILE)
	@echo STRIP	' ' $(KERNEL_NAME).elf

release: kernel _dummyrelease iso
	@echo Symbols stripped


distclean: debootstrap

toolchain:
	git clone https://github.com/ShadowDevZ/tc-bootstrapper.git -b stable
	python3 tc-bootstrapper/src/main.py -t gcc binutils -w tc-work -i $(_BOOTSTRAP_TC_INSTALL) -g -n $(_BOOTSTRAP_MAKEOPTS) --arch="x86_64-elf" --gcc_flags="-disable-nls --enable-languages=c,c++\
	 --without-headers" --gcc_version="LTS" -c -r -m --binutils_version="LTS" --binutils_flags="--with-sysroot --disable-nls --disable-werror" --libgcc_nored
	ln -s -r tc-install/x86_64-elf toolchain

asmdump: kernel
	@echo "; ***THIS ASMDUMP HAS BEEN AUTOGENERATED BY THE MAKEFILE***\n;SYNTAX: intel\n;ISA: x86_64\n;ENTRY_POINT: _start\n;KERNEL_MAIN: kmain\n" > $(SYM_DIR)/$(KERNEL_NAME).asmdump
	@$(TARGET_OBJDUMP) -C -d -mi386:x86-64:intel $(BUILD_DIR)/$(KERNEL_FILE) >> $(SYM_DIR)/$(KERNEL_NAME).asmdump
	@echo OD' ' $(KERNEL_NAME).asmdump



ksyms: kernel
	@$(TARGET_NM) -C $(BUILD_DIR)/$(KERNEL_FILE) --numeric-sort | grep -i -F " T " > $(SYM_DIR)/$(KERNEL_NAME).ksymx
	@awk {'print $$1 "\t" $$3'} $(SYM_DIR)/$(KERNEL_FILE).ksym > $(SYM_DIR)/$(KERNEL_FILE).ksym
	@awk {'print "0x" toupper($$1) "\t" $$3'} $(SYM_DIR)/$(KERNEL_NAME).ksymx | tee $(SYM_DIR)/$(KERNEL_NAME).ksym > /dev/null 2>&1
	@rm $(SYM_DIR)/$(KERNEL_NAME).ksymx
	@echo NM ' ' $(KERNEL_NAME).ksym
	@sed -i '1i#This file has been autogenerated' $(SYM_DIR)/$(KERNEL_NAME).ksym
	@python3 $(SCRIPTS_DIR)/symgen.py $(SYS_DIR)/gensym.c $(SYM_DIR)/$(KERNEL_NAME).ksym



bootstrap: limine
	@echo Bootstrapped
	

first_setup: _first_setup_dummy toolchain bootstrap
	

_first_setup_dummy:
	@echo Setting up project ...
	$(warning Did you look at $(CFG_DIR)/config.mk first ?)
	@read -p "Select: [y/N]" line; if [ $$line != "y" ]; then echo Exiting...; exit 1 ; fi

debootstrap: clean
	@echo DEBOOTSTRAPPING ...
	@rm -rf $(LIMINE_BOOT_DIR)
	@rm -f $(LIMINE_INC_DIR)/limine.h
	@rm -rf $(abspath src/kernel/dev/flanterm)

limine:	
	git clone https://github.com/limine-bootloader/limine.git --branch=$(LIMINE_BRANCH) --depth=1 $(LIMINE_BOOT_DIR)
#	$(MAKE) -C limine CC=gcc CFLAGS="-Wall -Wextra"
	$(MAKE) -C $(LIMINE_BOOT_DIR) CC="${HOST_CC}"
	@cp $(LIMINE_BOOT_DIR)/limine.h $(LIMINE_INC_DIR)
	@echo $(COLOR_GREEN)[DEP]$(COLOR_RESET) Successfully built Limine bootloader dependency

	git clone https://github.com/mintsuki/flanterm.git --depth=1 $(abspath src/kernel/dev/flanterm)

	


$(KERNEL_NAME).iso: kernel 
	@rm -rf $(BUILD_DIR)/iso
	@mkdir -p $(BUILD_DIR)/iso
	
	
	@cp $(BUILD_DIR)/$(KERNEL_FILE) $(CFG_DIR)/limine.conf $(LIMINE_BOOT_DIR)/limine-bios-cd.bin \
	$(LIMINE_BOOT_DIR)/limine-bios.sys  $(LIMINE_BOOT_DIR)/limine-uefi-cd.bin $(BUILD_DIR)/iso/

	@xorriso -as mkisofs -b limine-bios-cd.bin -no-emul-boot -boot-load-size 4 -boot-info-table \
	--protective-msdos-label --efi-boot limine-uefi-cd.bin --efi-boot-part --efi-boot-image \
	 $(BUILD_DIR)/iso -o $(BUILD_DIR)/iso/$(KERNEL_NAME).iso > /dev/null 2>&1

	@$(LIMINE_BOOT_DIR)/limine bios-install $(BUILD_DIR)/iso/$(KERNEL_NAME).iso > /dev/null 2>&1
	@cp $(BUILD_DIR)/iso/$(KERNEL_NAME).iso $(BUILD_DIR)
#	@/$(LIMINE_BOOT_DIR)/limine bios-install $(BUILD_DIR)/iso/$(KERNEL_NAME).iso
	@rm -rf $(BUILD_DIR)/iso/*
	@echo $(COLOR_GREEN)[ISO]$(COLOR_RESET) KERNEL IMAGE GENERATED $(BUILD_DIR)/nkos.iso
clean:
	@rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d $(BUILD_DIR)/*.iso $(BUILD_DIR)/*.elf $(SYM_DIR)/*


#endif
