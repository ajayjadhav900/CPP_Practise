#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
std::timed_mutex resourceMutex;


void PerformTask(int taskID, int duration)
{
    if (resourceMutex.try_lock_until( std::chrono::steady_clock::now() + std::chrono::seconds(duration)))
    {
        std::cout << "Task " << taskID << " acquired the resource." << std::endl;
        // Simulate task execution
        std::this_thread::sleep_for(std::chrono::seconds(duration));
        resourceMutex.unlock();
        std::cout << "Task " << taskID << " released the resource." << std::endl;
    }
    else
    {
        std::cout << "Task " << taskID << " failed to acquire the resource within the time constraint." << std::endl;
    }
}

int main()
{
    std::thread t1(PerformTask, 1, 2); // Task 1 with a 2-second deadline
    std::thread t2(PerformTask, 2, 3); // Task 2 with a 3-second deadline

    t1.join();
    t2.join();

    return 0;
}
