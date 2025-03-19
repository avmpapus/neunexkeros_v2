// Multiboot header
asm(".align 4\n"
    ".long 0x1BADB002\n"  // Magic number
    ".long 0x00\n"        // Flags
    ".long - (0x1BADB002 + 0x00)\n");  // Checksum

// Entry point for the kernel
extern "C" void kernel_main() {
    print("Hello, Kernel World!");
}

// Function to print to the screen
void print(const char* str) {
    unsigned short* VideoMemory = (unsigned short*)0xB8000;
    for (int i = 0; str[i] != '\0'; ++i) {
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
    }
}
