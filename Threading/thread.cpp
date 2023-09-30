#include <iostream>
#include <thread>
#include <mutex>
#include<atomic>
std::atomic<int> a;
std::mutex m1;

class Account
{
public:
    int Balance = 0;

    void AddBalance(int amt)
    {
        m1.try_lock();
        std::cout << "Adding balance: " << amt;
       
        std::this_thread::sleep_for(std::chrono::seconds(0));
        Balance = Balance + amt;
        m1.unlock();
        std::cout << "Current Balance: " << Balance << std::endl;
    }

    void WithdrawBalance(int amt)
    {
        m1.try_lock();
        std::cout << "Withdrawing balance: " << amt;
        std::this_thread::sleep_for(std::chrono::seconds(0));
        if (Balance >= amt)
        {
            Balance = Balance - amt;
        }
        else
            std::cout << "Insufficient Balance!!!" << std::endl;

        m1.unlock();
        std::cout << "Current Balance: " << Balance << std::endl;
    }
};

int main()
{
    Account A1;

    std::thread t1(&Account::AddBalance, &A1, 200);
    std::thread t2(&Account::WithdrawBalance, &A1, 100);
    std::thread t3(&Account::AddBalance, &A1, 2000);
    std::thread t4(&Account::WithdrawBalance, &A1, 100);
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "Final Balance: " << A1.Balance << std::endl;

    return 0;
}
