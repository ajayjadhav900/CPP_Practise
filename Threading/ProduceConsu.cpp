#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

int size = 5;
vector<int> buffer;
std::mutex m1;
int counter = 0;
std::condition_variable cv1, cv2;
bool canProdcuce = true;
bool canConsume = false;
void producer()
{
    std::unique_lock<std::mutex> lock1(m1);

    if (buffer.size() > 5)
    {
        cout << "\nbuffer full!!!";
        canProdcuce = false;
        canConsume = true;
        cv2.notify_one();
    }

    while (!canProdcuce)
    {
        cv1.wait(lock1);
    }

    cout << "\nProd: " << counter;
    buffer.push_back(counter++);
    canConsume = true;
    cv2.notify_one();
}
void consumer()
{

    std::unique_lock<std::mutex> lock2(m1);

    if (buffer.empty())
    {
        cout << "\n buffer empty !!! cant consume";
        canConsume = false;
        canProdcuce = true;
        cv1.notify_one();
    }

    while (!canConsume)
    {
        cv2.wait(lock2);
    }
    cout << "\nCons: " << buffer[buffer.size() - 1];
    buffer.pop_back();
    canProdcuce = true;
    cv1.notify_one();
}
int main()
{
    for (int i = 0; i < 4; i++)
    {
        thread t2(consumer);
        thread t1(producer);
        thread t3(producer);
        thread t4(consumer);
        t1.join();
        t3.join();
        t2.join();
        t4.join();
    }

    

}