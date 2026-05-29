// FIFO 页面置换算法

#include <stdio.h>

int main() {
    int frames, n, pageFaults = 0, front = 0;
    printf("物理块数: ");
    scanf("%d", &frames);
    printf("引用序列长度: ");
    scanf("%d", &n);
    int ref[n];
    printf("输入引用序列: ");
    for (int i = 0; i < n; i++) scanf("%d", &ref[i]);
    
    int mem[frames];
    for (int i = 0; i < frames; i++) mem[i] = -1;
    
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++)
            if (mem[j] == ref[i]) { found = 1; break; }
        if (!found) {
            mem[front] = ref[i];
            front = (front + 1) % frames;
            pageFaults++;
        }
        printf("引用 %d: ", ref[i]);
        for (int j = 0; j < frames; j++) printf("%d ", mem[j]);
        printf("\n");
    }
    printf("缺页次数: %d\n", pageFaults);
    return 0;
} 
