#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    // 第一部分：产生僵尸进程 
    pid_t pid1 = fork();
    
    if (pid1 < 0) {
        perror("fork1 failed");
        return 1;
    }
    
    if (pid1 == 0) {
        printf("子进程1 (PID=%d) 退出。\n", getpid());
        exit(0);
    } else {
        printf("父进程 (PID=%d) 未调用 wait，子进程1 (PID=%d) 将变成僵尸进程。\n", getpid(), pid1);
        sleep(2);
        system("ps aux | grep defunct | grep -v grep");
    }
    
    // 第二部分：产生孤儿进程
    pid_t pid2 = fork();
    
    if (pid2 < 0) {
        perror("fork2 failed");
        return 1;
    }
    
    if (pid2 == 0) {
        printf("子进程2 (PID=%d) 开始，父进程 PID=%d\n", getpid(), getppid());
        sleep(3);
        printf("子进程2 现在父进程 PID=%d（被 init 收养）\n", getppid());
    } else {
        printf("父进程 (PID=%d) 即将退出，子进程2 (PID=%d) 将变成孤儿进程。\n", getpid(), pid2);
        exit(0);
    }
    
    return 0;
}