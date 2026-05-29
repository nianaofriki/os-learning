// mmap 内存映射示例
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char* filename = "test.txt";
    const char* content = "Hello, mmap!";
    
    int fd = open(filename, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    write(fd, content, strlen(content));
    
    char* mapped = (char*)mmap(NULL, 1024, PROT_READ | PROT_WRITE,
                               MAP_SHARED, fd, 0);
    if (mapped == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }
    
    printf("原始: %s\n", mapped);
    mapped[0] = 'H';
    mapped[1] = 'i';
    printf("修改后: %s\n", mapped);
    
    munmap(mapped, 1024);
    close(fd);
    return 0;
}