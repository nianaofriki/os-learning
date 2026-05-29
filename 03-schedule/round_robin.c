// 时间片轮转 (RR)
#include <stdio.h>

#define MAX 100

typedef struct {
    int pid, arrival, burst, remaining, start, finish, turnaround, wait, first;
} Process;

int main() {
    int n, quantum, time = 0, completed = 0;
    printf("进程数: ");
    scanf("%d", &n);
    printf("时间片: ");
    scanf("%d", &quantum);
    Process p[n];
    int queue[MAX], front = 0, rear = 0;
    int inQueue[MAX] = {0};
    for (int i = 0; i < n; i++) {
        p[i].pid = i+1;
        printf("P%d 到达时间 执行时间: ", i+1);
        scanf("%d%d", &p[i].arrival, &p[i].burst);
        p[i].remaining = p[i].burst;
        p[i].first = 1;
        inQueue[i] = 0;
    }
    // 初始入队
    for (int i = 0; i < n; i++)
        if (p[i].arrival <= time && !inQueue[i]) {
            queue[rear++] = i;
            inQueue[i] = 1;
        }
    while (completed < n) {
        if (front == rear) {
            time++;
            for (int i = 0; i < n; i++)
                if (p[i].arrival <= time && !inQueue[i] && p[i].remaining > 0) {
                    queue[rear++] = i;
                    inQueue[i] = 1;
                }
            continue;
        }
        int idx = queue[front++];
        inQueue[idx] = 0;
        if (p[idx].first) {
            p[idx].start = time;
            p[idx].first = 0;
        }
        int exec = (p[idx].remaining < quantum) ? p[idx].remaining : quantum;
        time += exec;
        p[idx].remaining -= exec;
        // 新到达的进程入队
        for (int i = 0; i < n; i++)
            if (p[i].arrival <= time && !inQueue[i] && p[i].remaining > 0) {
                queue[rear++] = i;
                inQueue[i] = 1;
            }
        if (p[idx].remaining > 0) {
            queue[rear++] = idx;
            inQueue[idx] = 1;
        } else {
            p[idx].finish = time;
            p[idx].turnaround = p[idx].finish - p[idx].arrival;
            p[idx].wait = p[idx].turnaround - p[idx].burst;
            completed++;
        }
    }
    float totalT = 0, totalW = 0;
    printf("\n进程\t到达\t执行\t开始\t完成\t周转\t等待\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst,
               p[i].start, p[i].finish, p[i].turnaround, p[i].wait);
        totalT += p[i].turnaround;
        totalW += p[i].wait;
    }
    printf("\n平均周转时间: %.2f\n", totalT/n);
    printf("平均等待时间: %.2f\n", totalW/n);
    return 0;
}
 
