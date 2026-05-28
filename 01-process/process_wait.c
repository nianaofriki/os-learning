#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h> 

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        printf("子进程 (PID=%d) 开始工作...\n", getpid());
        sleep(2);
        printf("子进程 (PID=%d) 工作完成，退出。\n", getpid());
        exit(0);
    }
    else {
        printf("父进程 (PID=%d) 等待子进程 (PID=%d) 结束...\n", getpid(), pid);
        int status;
        wait(&status);
        printf("父进程：子进程已退出，回收成功。\n");
        if (WIFEXITED(status)) {
            printf("子进程正常退出，退出码：%d\n", WEXITSTATUS(status));
        }
    }
    
    return 0;
}
