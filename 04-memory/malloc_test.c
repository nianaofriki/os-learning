// malloc / free 使用示例

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("输入数组大小: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("内存分配失败\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++)
        arr[i] = i * 10;
    
    printf("数组: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    free(arr);
    return 0;
}