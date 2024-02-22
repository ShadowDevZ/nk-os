# nk-os
Hobyist x64 kernel
Requirements: elf compatible x64 cross compiler (auto script will be added in future update to match all requirements),
limine bootloader `v5.x` is pulled and builded as dependency automatically. Note newer version than 4 won't work beacuse the developer
decided to remove the limine_terminal feature from version 5 and newer releases. 

In the future the os is going to use custom linear framebuffer

Build is currently only supported on linux (the script requires /dev/null device, will make it compatible for windows in future)
!!!Bochs may not work properly if it was not compiled with graphics option!!!
- xorriso
- bash
- nm
- od
- nasm
- CC and LD (for dependencies)
- qemu or any emulator which is able to handle x64 iso and graphics mode
- objdump
- awk
- git
- gdb
- git
- python3 (pathlib, os, sys)
- VT100 compatible terminal that supports ANSI escape sequence for colored output

TODO: 
- dependency checking and install if supported by system
- script for generating cross compiler, need to set the symlink in `confik.mk`

TODOLIST: 
- &#9745; Basic printing
- &#9745; Better framebuffer interface
- &#9745; GDT
- &#9745; IDT
- &#9745; ISR
- &#9745; Kernel symbols
- &#9745; Versioning scheme
- &#9745; Limine bootloader
- &#9744; HAL
- &#9745; IRQ
- &#9744; Better build system (CMake)
- &#9744; TSS
- &#9745; PIT
- &#9745; PIC
- &#9745; PS2 keyboard
- &#9745; Debugging support
- &#9744; Paging
- &#9744; VMM
- &#9744; PMM
- &#9744; SMP
- &#9744; TarFS (bsd or ustar)
- &#9744; Threads
- &#9744; Custom remote debugger using unix socket via qemu
- &#9744; Usermode
- &#9744; ACPI
- &#9744; Kernel driver interface
- &#9745; Kernel main
- &#9744; Kconfig like customization
- &#9744; µGUI port
- &#9744; More user friendly toolchain builder
- &#9744; C++ support
- &#9744; Device manager
- &#9744; ATA support
- &#9744; AHCI support
- &#9744; Fat32 file system
- &#9744; Virtual filesystem
- &#9745; Logging
- &#9744; Network
- &#9744; Serial debugging
- &#9744; Processes
- &#9744; Kernel libc
- &#9744; libc
- &#9744; libsys
- &#9744; PCI driver
- &#9744; APIC
- &#9744; HPET
- &#9744; Syscalls
- &#9745; FPU
- &#9745; SSE
- &#9745; kernel error reporting


# External used libraries and assets
[printf library](https://github.com/mpaland/printf/tree/master) MIT license \
[limine bootloader](https://github.com/limine-bootloader/limine) BSD-2-Clause license
[framebuffer](https://github.com/mintsuki/flanterm)
