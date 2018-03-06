#ifndef THREADPOOL_H
#define THREADPOOL_H


#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
#include <mutex>

class threadPool
{
public:
    threadPool(int thread_count=0);
    ~threadPool();
    void thread_assigner(std::function<void()> working_function);
    void finder(int i);

private:
    int thread_counts;
    std::vector<std::thread> workers_thread;
    std::vector<bool> thread_status;
    std::queue<std::function<void()>> waiting_functions;
    std::mutex queuemutex;
    std::condition_variable work_available;
    bool stop;
};
#endif // THREADPOOL_H

