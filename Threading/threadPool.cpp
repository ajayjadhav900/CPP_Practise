#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>

class ThreadPool
{
private:
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;

public:
    ThreadPool(size_t numThreads) : stop(false)
    {
        for (size_t i = 0; i < numThreads; ++i)
        {
            threads.emplace_back([this]
                                 {
                while (true) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(queueMutex);
                        condition.wait(lock, [this] { return stop || !tasks.empty(); });
                        if (stop && tasks.empty()) {
                            return;
                        }
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                } });
         }
    }

    ~ThreadPool()
    {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            stop = true;
        }
        condition.notify_all();
        for (std::thread &thread : threads)
        {
            thread.join();
        }
    }

    template <typename F>
    void enqueue(F &&f)
    {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            tasks.emplace(std::forward<F>(f));
        }
        condition.notify_one();
    }
};

int main()
{
    ThreadPool pool(4); // Create a thread pool with 4 threads

    for (int i = 0; i < 8; ++i)
    {
        pool.enqueue([i]
                     { std::cout << "Task "
                      << i << 
                      " executed by thread " << std::this_thread::get_id() << std::endl; });
    }

    // Tasks are executed concurrently by the thread pool

    return 0;
}
