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
    threadPool(int thread_count);
    ~threadPool();
    void thread_adder();
    void thread_assigner(std::function<void()> working_function);
    void finder(int i);
    void waiting_all();

private:
    int thread_counts;
    std::vector<std::thread> workers_thread;
    std::vector<bool> thread_status;
    std::queue<std::function<void()>> waiting_functions;
    std::mutex queuemutex;
    std::condition_variable work_available;
    std::mutex queue_empty;
    std::condition_variable available;
    std::condition_variable wait_thread;
    std::mutex wait_mutex;
    bool waiting;
    bool stop;
};
#endif // THREADPOOL_H
