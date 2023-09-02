#! /bin/bash

	#@qemu-system-i386 -append "example command line argument" -debugcon stdio -hda scripts/disk.raw -kernel $(BUILD_DIR)/iso/boot/$(KERNEL_FILE)


QEMU_ARGS="-S -gdb stdio -m 32 -cdrom $PWD/build/nkos.elf -append debug"

cat > $PWD/.gdb_script.gdb << EOF
    symbol-file $PWD/build/nkos.elf
    set disassembly-flavor intel
    target remote | qemu-system-x86_64 $QEMU_ARGS

EOF

gdb -x .gdb_script.gdb
