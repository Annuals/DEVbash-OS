if ! which nasm > /dev/null; then sudo apt-get install nasm; fi
if ! which qemu-system-i386 > /dev/null; then sudo apt-get install qemu; fi


nasm -f elf32 kernel.asm -o kernelasm.o
gcc -m32 -c kernel.c -o kernelc.o
ld -m elf_i386 -T link.ld -o kernel.bin kernelasm.o kernelc.o


qemu-system-i386 -kernel kernel.bin
