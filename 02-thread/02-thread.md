# 线程管理笔记

## 1. 线程创建 (thread_basic.c)
- `pthread_create()` 创建线程，`pthread_join()` 等待。
- 参数传递需注意生命周期。

## 2. 多线程 (thread_multi.c)
- 多个线程可同时运行，共享进程地址空间。

## 3. 互斥锁 (thread_mutex.c)
- `pthread_mutex_lock` / `unlock` 保护共享变量，避免竞争条件。
- 临界区应尽量短小。

## 编译
- 所有程序需链接 `pthread` 库：`gcc xxx.c -o xxx -lpthread`