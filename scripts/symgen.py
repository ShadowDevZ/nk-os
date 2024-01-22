#! /bin/python3
import sys
import os
from pathlib import Path


g_symbolList = []

includeHeaders = [
        '"kstdio.h"',
        '"ksyms.h"',
        '<stddef.h>'
        ]

def ReadError():
    print("File is either corrupted or has been manually altered")
    sys.exit(1)

def ParseSymbols(f2r):

    f = open(f2r, "r")
    for ln in f:
        if ln.startswith("#"):
            continue
    
        addr = ln.split()[0]
        symName = ln.split()[1]
        if (not addr.startswith("0x")):
            ReadError()

        g_symbolList.append([addr, symName])

    f.close()

def WriteSymbols(f2w):
    f = open(f2w, "w")
    f.write("//This file has been generated by symgen.py\n")
    for hdr in includeHeaders:
        f.write("#include " +  hdr + "\n")

    f.write("\n\n")
    f.write("#pragma GCC diagnostic push\n")
    f.write("#pragma GCC diagnostic ignored \"-Wint-conversion\"\n")
    f.write("#pragma GCC diagnostic ignored \"-Wmissing-braces\"\n")

    f.write("const KsymList __symbols__[] = {\n")
    for sym in g_symbolList:
          f.write("{ " + sym[0] + ",\""+ sym[1] + "\"},\n")

    f.write("{NULL, NULL}\n")
    f.write("};\n")

    f.write("#pragma GCC diagnostic pop\n")
    f.close()

def Usage():
    print("Usage:", sys.argv[0], "<file>.c <symbolstoread.ksym>")
    sys.exit(2)



if len(sys.argv) < 3:
    Usage()

if (Path(sys.argv[1]).suffix != ".c"):
    print("To avoid overwriting of uwanted files only *.c extensions are allowed")
    Usage()

if (Path(sys.argv[2]).suffix != ".ksym"):
    print("Only files of ksym format are allowed")
    Usage()

if (not os.path.isfile(sys.argv[2])):
    print(sys.argv[2] + " does not exist")
    sys.exit(3)
ParseSymbols(sys.argv[2])
WriteSymbols(sys.argv[1])
print(">>Symbol files have been generated")


