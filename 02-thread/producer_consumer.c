#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_func(void* arg) {
    int* num = (int*)arg;
    printf("子线程 %d: PID=%d, TID=%lu\n", *num, getpid(), pthread_self());
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int arg1 = 1, arg2 = 2;
    
    // 创建线程
    pthread_create(&t1, NULL, thread_func, &arg1);
    pthread_create(&t2, NULL, thread_func, &arg2);
    
    // 等待线程结束
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    printf("主线程退出\n");
    return 0;
} 
