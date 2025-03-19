void put_string(const char* str, unsigned char color) {
    unsigned short* video_memory = (unsigned short*) 0xB8000;
    int i = 0;
    while (str[i] != '\0') {
        video_memory[i] = (color << 8) | str[i];
        i++;
    }
}
