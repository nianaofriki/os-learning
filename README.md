# 操作系统学习

操作系统核心概念的学习笔记和代码实现。

---

## 目录结构

| 目录 | 内容 | 状态 |
|------|------|------|
| `01-process/` | 进程管理（fork、wait、孤儿/僵尸进程） | ⬜ |
| `02-thread/` | 线程管理（pthread、互斥锁、生产者消费者） | ⬜ |
| `03-schedule/` | 调度算法（FCFS、SJF、优先级、时间片轮转） | ⬜ |
| `04-memory/` | 内存管理（malloc、mmap、页面置换FIFO/LRU/Clock） | ⬜ |
| `05-ipc/` | 进程间通信（管道、共享内存、消息队列） | ⬜ |
| `06-deadlock/` | 死锁（银行家算法、死锁检测） | ⬜ |
| `07-file-system/` | 文件系统（文件创建、读写、目录操作） | ⬜ |
| `notes/` | 手写笔记照片 | ⬜ |

---

## 如何运行

所有代码在 **Linux / WSL** 环境下编译运行。

```bash
# 编译
gcc filename.c -o filename

# 运行
./filename