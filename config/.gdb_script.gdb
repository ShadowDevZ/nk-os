symbol-file /home/shadow/Projects/OperatingSystems/nkos/build/nkos.elf
set disassembly-flavor intel
target remote | qemu-system-x86_64 -M q35 -m 256 -s -S -serial stdio -cdrom /home/shadow/Projects/OperatingSystems/nkos/build/nkos.iso -boot d