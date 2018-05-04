#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <thread>
#include <mutex>
#include <functional>
#include <string>
#include <condition_variable>
#include <queue>
#include <vector>
#include <memory>

#include "nocopyable.h"
using namespace std;

namespace myPool
{
class ThreadPool:public nocopyable {

public:
    typedef function<void()> Task;

    explicit ThreadPool(const string &name = string());
    ~ThreadPool();


    void start(int numThreads);//设置线程数，创建numThreads个线程
    void stop();//线程池结束
    void run(const Task& f);//任务f在线程池中运行
    void setMaxQueueSize(int maxSize);//设置任务队列可存放最大任务数

private:
    bool isFull();//任务队列是否已满
    void runInThread();//线程池中每个thread执行的function
    Task take();//从任务队列中取出一个任务

    mutex poolMutex;
    string poolName;
    vector<std::thread> myThreads;
    queue<Task> threadQueue;
    size_t maxQueueSize;
    bool isRunning;
    condition_variable isNotEmpty;
    condition_variable isNotFull;
};
}

#endif // THREADPOOL_H
