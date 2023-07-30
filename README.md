# nk-os
Hobyist x64 kernel
Requirements: elf compatible x64 cross compiler (auto script will be added in future update to match all requirements),
limine bootloader `v4.x` is pulled and builded as dependency automatically. Note newer version than 4 won't work beacuse the developer
decided to remove the limine_terminal feature from version 5, 

Build is currently only supported on linux (the script requires /dev/null device, will make it compatible for windows in future)
!!!Bochs may not work properly if it was not compiled with graphics option!!!
- xorriso
- nm
- od
- nasm
- CC and LD (for dependencies)
- qemu or any emulator which is able to handle x64 iso and graphics mode
- objdump
- awk
- git
- VT100 compatible terminal that supports ANSI escape sequence for colored output

TODO: 
- dependency checking and install if supported by system
- script for generating cross compiler, need to set the symlink in `confik.mk`

TODOLIST: 
- ✅ Basic printing
