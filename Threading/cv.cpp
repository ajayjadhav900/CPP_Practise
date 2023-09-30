
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;

int Balance = 0;
mutex BalanceMutex;
std::condition_variable cv_balance;
void DepositeMoney(int amt)
{
    lock_guard<std::mutex> BalanceUniqLock(BalanceMutex);
    Balance = Balance + amt;
    cout << "Deposited the amount: " << amt << " Current Balance: " << Balance << endl;
    cv_balance.notify_all();
}

bool isBalanceSufficient(int amt)
{
    return Balance >= amt;
}
void WithdrawMoney(int amt)
{
    unique_lock<std::mutex> BalanceUniqLock2(BalanceMutex);

    cv_balance.wait(BalanceUniqLock2, std::bind(isBalanceSufficient, amt));
    Balance = Balance - amt;
    cout << "Withdraw the amount: " << amt << " Current Balance: " << Balance << endl;
}
int main()
{

    vector<thread> threads;
    
    // Create multiple threads for withdrawal
    for (int i = 0; i < 5; ++i)
    {
        threads.emplace_back(WithdrawMoney, 200); // Withdraw 200 in each thread
    }

    // Deposit money to the account
    DepositeMoney(1000);

    for (auto& t : threads)
    {
        t.join();
    }
}