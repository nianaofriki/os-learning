#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 线程函数
void* thread_func(void* arg) {
    int num = *(int*)arg;
    printf("子线程: 线程ID = %lu, 接收参数 = %d\n", pthread_self(), num);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int val1 = 100, val2 = 200;
    
    // 创建线程1
    if (pthread_create(&t1, NULL, thread_func, &val1) != 0) {
        perror("pthread_create t1 failed");
        return 1;
    }
    
    // 创建线程2
    if (pthread_create(&t2, NULL, thread_func, &val2) != 0) {
        perror("pthread_create t2 failed");
        return 1;
    }
    
    // 等待两个线程结束
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    printf("主线程: 所有子线程已结束\n");
    return 0;
}