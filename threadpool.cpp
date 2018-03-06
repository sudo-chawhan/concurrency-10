#include "threadpool.h"
#include <QDebug>
#include <QThread>

threadPool::threadPool(int number_of_threads )
{
    if(number_of_threads <= 0)
    {
        number_of_threads = std::thread::hardware_concurrency();
    }
    thread_counts = number_of_threads;
    for(int i = 0; i < number_of_threads; i++)
    {
        std::thread t = std::thread(&threadPool::finder,this,i);
        workers_thread.push_back(std::move(t));
        thread_status.push_back(true);
        workers_thread[i].detach();
    }
    stop = false;
}

void threadPool::thread_assigner(std::function<void()> working_function)
{
    waiting_functions.push(working_function);
    work_available.notify_one();
}

void threadPool::finder(int i)
{
    while(true)
    {
        std::unique_lock<std::mutex> lock(queuemutex);
        work_available.wait(lock, [&](){ return !waiting_functions.empty(); });
        std::function<void()> work_to_do = waiting_functions.front();
        waiting_functions.pop();
        work_to_do();
        if(stop)
        {
            break;
        }
    }
    thread_status[i] = false;
}


threadPool::~threadPool()
{
   stop = true;
   while(thread_status.size())
   {
       for(unsigned int i = 0; i < thread_status.size(); i++)
       {
           if(thread_status[i] == false)
           {
               thread_status.erase(thread_status.begin() + i);
               i = -1;
           }
       }
   }
}
