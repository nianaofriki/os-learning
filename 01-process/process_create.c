#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();
    if(pid<0){
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        printf("子进程: PID = %d, 父进程 PID = %d\n", getpid(), getppid());
    } 
    else {
        printf("父进程: PID = %d, 子进程 PID = %d\n", getpid(), pid);
        wait(NULL);
    }
    return 0;
}
