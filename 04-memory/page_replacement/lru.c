// LRU 页面置换算法

#include <stdio.h>
#include <limits.h>

int main() {
    int frames, n, pageFaults = 0;
    printf("物理块数: ");
    scanf("%d", &frames);
    printf("引用序列长度: ");
    scanf("%d", &n);
    int ref[n];
    printf("输入引用序列: ");
    for (int i = 0; i < n; i++) scanf("%d", &ref[i]);
    
    int mem[frames], lastUsed[frames];
    for (int i = 0; i < frames; i++) mem[i] = -1;
    
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (mem[j] == ref[i]) {
                found = 1;
                lastUsed[j] = i;
                break;
            }
        }
        if (!found) {
            int lru = 0, minTime = INT_MAX;
            for (int j = 0; j < frames; j++) {
                if (mem[j] == -1) { lru = j; break; }
                if (lastUsed[j] < minTime) {
                    minTime = lastUsed[j];
                    lru = j;
                }
            }
            mem[lru] = ref[i];
            lastUsed[lru] = i;
            pageFaults++;
        }
        printf("引用 %d: ", ref[i]);
        for (int j = 0; j < frames; j++) printf("%d ", mem[j]);
        printf("\n");
    }
    printf("缺页次数: %d\n", pageFaults);
    return 0;
}