// 优先级调度（非抢占，数字小优先级高）
#include <stdio.h>
#include <limits.h>

typedef struct {
    int pid, arrival, burst, priority, start, finish, turnaround, wait, done;
} Process;

int main() {
    int n, completed = 0, cur = 0;
    printf("进程数: ");
    scanf("%d", &n);
    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i+1;
        printf("P%d 到达时间 执行时间 优先级: ", i+1);
        scanf("%d%d%d", &p[i].arrival, &p[i].burst, &p[i].priority);
        p[i].done = 0;
    }
    while (completed < n) {
        int idx = -1, bestPriority = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].arrival <= cur && p[i].priority < bestPriority) {
                bestPriority = p[i].priority;
                idx = i;
            }
        }
        if (idx != -1) {
            p[idx].start = cur;
            p[idx].finish = cur + p[idx].burst;
            p[idx].turnaround = p[idx].finish - p[idx].arrival;
            p[idx].wait = p[idx].start - p[idx].arrival;
            cur = p[idx].finish;
            p[idx].done = 1;
            completed++;
        } else {
            cur++;
        }
    }
    float totalT = 0, totalW = 0;
    printf("\n进程\t到达\t执行\t优先\t开始\t完成\t周转\t等待\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst,
               p[i].priority, p[i].start, p[i].finish, p[i].turnaround, p[i].wait);
        totalT += p[i].turnaround;
        totalW += p[i].wait;
    }
    printf("\n平均周转时间: %.2f\n", totalT/n);
    printf("平均等待时间: %.2f\n", totalW/n);
    return 0;
}