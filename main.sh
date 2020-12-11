if ! which nasm > /dev/null; then install-pkg nasm; fi
if ! which qemu-system-i386 > /dev/null; then install-pkg qemu; fi


nasm -f elf32 ./OS/kernel.asm -o ./OS/kernelasm.o
gcc -m32 -c ./OS/kernel.c -o ./OS/kernelc.o
ld -m elf_i386 -T link.ld -o ./OS/kernel.bin ./OS/kernelasm.o ./OS/kernelc.o


qemu-system-i386 -kernel kernel.bin