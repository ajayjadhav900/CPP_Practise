#include <iostream>
using namespace std;
#include "chainofres.hpp"

void ConcreteHandle1::HandleRequest(int req)
{
    if (req <= 10)
    {
        cout << "I am handler1 , handling the request : " <<req<<endl;
    }
    else
    {
        Successor->HandleRequest(req);
    }
}

void ConcreteHandle2::HandleRequest(int req)
{
    if (req > 10 && req <= 20)
    {
        cout << "I am handler2 , handling the  :" << req<<endl;
    }
    else
    {
        Successor->HandleRequest(req);
    }
}

void ConcreteHandle3::HandleRequest(int req)
{
    if (req > 20 && req <= 30)
    {
        cout << "I am handler3 , handling the request : " << req<<endl;
    }
    else
    {
        Successor->HandleRequest(req);
    }
}

int main()
{

    int request[13] = {1, 3, 23, 12, 5, 6, 16, 13, 11, 23, 22, 27, 3};
    Handler *h1 = new ConcreteHandle1();
    Handler *h2 = new ConcreteHandle2();
    Handler *h3 = new ConcreteHandle3();
    h1->SetSuccessor(h2);
    h2->SetSuccessor(h3);

    for (int i = 0; i < 13; i++)
    {
        h1->HandleRequest(request[i]);
    }
}