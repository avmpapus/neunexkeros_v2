// filepath: /home/sasha/myfirstos/multiboot.h
#ifndef MULTIBOOT_H
#define MULTIBOOT_H

#define MULTIBOOT_MAGIC 0x1BADB002
#define MULTIBOOT_FLAG  0x0
#define MULTIBOOT_CHECKSUM -(MULTIBOOT_MAGIC + MULTIBOOT_FLAG)

struct multiboot_info {
    unsigned int flags;
    unsigned int mem_lower;
    unsigned int mem_upper;
    // Інші поля можна додати за потреби
};

#endif // MULTIBOOT_H