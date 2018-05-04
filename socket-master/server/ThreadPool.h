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


    void start(int numThreads);//�����߳���������numThreads���߳�
    void stop();//�̳߳ؽ���
    void run(const Task& f);//����f���̳߳�������
    void setMaxQueueSize(int maxSize);//����������пɴ�����������

private:
    bool isFull();//��������Ƿ�����
    void runInThread();//�̳߳���ÿ��threadִ�е�function
    Task take();//�����������ȡ��һ������

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
