#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

const int NumPhilosophers = 5;
std::mutex forks[NumPhilosophers];
std::condition_variable cv[NumPhilosophers];

void philosopher(int id) {
    int left_fork = id;
    int right_fork = (id + 1) % NumPhilosophers;

    while (true) {
        // Think
        std::cout << "Philosopher " << id << " is thinking" << std::endl;
        
        // Pick up forks
        std::unique_lock<std::mutex> left_lock(forks[left_fork]);
        std::unique_lock<std::mutex> right_lock(forks[right_fork]);

        // Eat
        std::cout << "Philosopher " << id << " is eating" << std::endl;
        
        // Put down forks
        left_lock.unlock();
        right_lock.unlock();

        // Sleep a bit before next cycle
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int main() {
    std::thread philosophers[NumPhilosophers];

    for (int i = 0; i < NumPhilosophers; ++i) {
        philosophers[i] = std::thread(philosopher, i);
    }

    for (int i = 0; i < NumPhilosophers; ++i) {
        philosophers[i].join();
    }

    return 0;
}
