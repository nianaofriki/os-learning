// 来先服务调度算法 (FCFS)
#include <stdio.h>

typedef struct {
    int pid, arrival, burst, start, finish, turnaround, wait;
} Process;

int main() {
    int n;
    printf("进程数: ");
    scanf("%d", &n);
    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i+1;
        printf("P%d 到达时间 执行时间: ", i+1);
        scanf("%d%d", &p[i].arrival, &p[i].burst);
    }
    // 按到达时间排序
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-1-i; j++)
            if (p[j].arrival > p[j+1].arrival) {
                Process t = p[j]; p[j] = p[j+1]; p[j+1] = t;
            }
    int cur = 0;
    float totalT = 0, totalW = 0;
    for (int i = 0; i < n; i++) {
        if (cur < p[i].arrival) cur = p[i].arrival;
        p[i].start = cur;
        p[i].finish = cur + p[i].burst;
        p[i].turnaround = p[i].finish - p[i].arrival;
        p[i].wait = p[i].start - p[i].arrival;
        cur = p[i].finish;
        totalT += p[i].turnaround;
        totalW += p[i].wait;
    }
    printf("\n进程\t到达\t执行\t开始\t完成\t周转\t等待\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst,
               p[i].start, p[i].finish, p[i].turnaround, p[i].wait);
    printf("\n平均周转时间: %.2f\n", totalT/n);
    printf("平均等待时间: %.2f\n", totalW/n);
    return 0;
} 
