#include "ThreadPool.h"
#include <cassert>

using namespace myPool;
using namespace std;

ThreadPool::ThreadPool(const string &name): poolName(name), maxQueueSize(0), isRunning(false) {

}

ThreadPool::~ThreadPool() {
    if(isRunning) {
        stop();
    }
}

void ThreadPool::start(int numThreads) {
    assert(myThreads.empty());
    int i = 0;
    isRunning = true;
    myThreads.reserve(numThreads);

    while(i < numThreads) {
        myThreads.push_back(thread(&ThreadPool::runInThread,this));
        i += 1;
    }
}

void ThreadPool::stop() {
    {
        unique_lock<mutex>  lock(poolMutex);
        isRunning = false;
        isNotEmpty.notify_all();
    }

    size_t i = 0;
    size_t numOfThreads = myThreads.size();
    while(i < numOfThreads) {
        myThreads[i].join();
        i += 1;
    }
}

void ThreadPool::run(const Task &t) {
    if(myThreads.empty()) {
        t();
    } else {
        unique_lock<mutex> lock(poolMutex);
        while(isFull()) {
            isNotFull.wait(lock);
        }

        assert(!isFull());
        threadQueue.push(t);
        isNotEmpty.notify_one();
    }
}

void ThreadPool::setMaxQueueSize(int maxSize) {
    maxQueueSize = maxSize;
}

ThreadPool::Task ThreadPool::take() {
    unique_lock<mutex> lock(poolMutex);

    while(isRunning && threadQueue.empty()) {
        isNotEmpty.wait(lock);
    }

    Task task;
    if(!threadQueue.empty()) {
        task = threadQueue.front();
        threadQueue.pop();

        if(maxQueueSize > 0) {
            isNotFull.notify_one();
        }
    }
    return task;
}

bool ThreadPool::isFull()
{
    return maxQueueSize > 0 && threadQueue.size() >= maxQueueSize;
}


void ThreadPool::runInThread()
{
    try
    {
        while(isRunning)
        {
            Task task = take();
            if(task)
            {
                task();
            }
        }
    }
    catch (const exception& ex)
    {
        fprintf(stderr, "exception caught in ThreadPool %s\n", poolName.c_str());
        fprintf(stderr, "reason: %s\n", ex.what());
        abort();
    }
    catch(...)
    {
        fprintf(stderr, "exception caught in ThreadPool %s\n", poolName.c_str());
    }
}
