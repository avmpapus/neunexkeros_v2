#include "interface.h"
#include <multiboot.h>

// Multiboot заголовок через inline-асемблер
asm(".section .multiboot\n"
    ".align 4\n"
    ".long 0x1BADB002\n"  // Magic number
    ".long 0x00\n"        // Flags
    ".long -(0x1BADB002 + 0x00)\n");  // Checksum

    extern "C" void kernel_main() {
        const char *greeting = "Welcome to OS!";
        unsigned short *video_memory = (unsigned short*) 0xB8000;
        int row = 0, col = 0;
    
        // Виведення привітання на екран
        for (int i = 0; greeting[i] != '\0'; i++) {
            video_memory[row * 80 + col] = (0x07 << 8) | greeting[i];
            col++;
        }
    
        // Затримка для перевірки привітання (зменшено тривалість)
        for (volatile int i = 0; i < 2000000000; i++); // Зменшено значення
    
        // Виклик функції для малювання інтерфейсу
        draw_interface();
    
        // Головний цикл ядра
        while (1);
    }