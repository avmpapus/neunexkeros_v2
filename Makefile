CXX = i686-elf-g++
CXXFLAGS = -ffreestanding -O2 -Wall -Wextra -I.
LDFLAGS = -T linker.ld -nostdlib -lgcc

# Компоновка multiboot.asm
multiboot.o: multiboot.asm
	nasm -f elf multiboot.asm -o multiboot.o

# Основне завдання для створення ISO
all: kernel.bin

kernel.bin: kernel.o interface.o video.o
	$(CXX) -o $@ $^ $(LDFLAGS)


# Компіляція kernel.cpp
kernel.o: kernel.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Компіляція interface.cpp
interface.o: interface.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Компіляція video.cpp
video.o: video.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Створення ISO-образу
iso: kernel.bin
	mkdir -p iso/boot/grub
	cp kernel.bin iso/boot/
	cp grub.cfg iso/boot/grub/
	grub-mkrescue -o myfirstos.iso iso

# Запуск за допомогою QEMU
run: iso
	qemu-system-i386 -cdrom myfirstos.iso

# Очищення всіх тимчасових файлів
clean:
	rm -rf *.o kernel.bin myfirstos.iso iso/
