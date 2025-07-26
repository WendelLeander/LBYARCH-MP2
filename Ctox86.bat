nasm -f win64 ASMfile.asm
gcc -c Cfile.c -o Cfile.obj -m64
gcc Cfile.obj ASMfile.obj -o Cfile.exe -m64
Cfile.exe