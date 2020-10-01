#ifndef THREADPOOL_H
#define THREADPOOL_H


#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
#include <mutex>

/**
 * @brief Initially creates some threads
 */
class threadPool
{
public:

    /**
     * @brief threadPool constructor
     * @param number_of_thread
     */
    threadPool(int number_of_thread=0);

    /**
      *destructor
     */
    ~threadPool();

    /**
     * @brief thread_assigner
     * @param function to be executed by the given thread
     */
    void thread_assigner(std::function<void()> working_function);

    /**
     * @brief finds whether the thread is waiting or busy
     * @param id of the thread
     */
    void finder(int i);

private:

    /**
     * @brief number of thread in threadpool
     */
    int thread_counts;

    /**
     * @brief workers_thread stores the working thread in a vector
     */
    std::vector<std::thread> workers_thread;

    /**
     * @brief thread_status
     */
    std::vector<bool> thread_status;

    /**
     * @brief waiting_functions stores the function that are waiting to be executed
     */
    std::queue<std::function<void()>> waiting_functions;

    std::mutex queuemutex;
    std::condition_variable work_available;
    bool stop;
};
#endif // THREADPOOL_H

