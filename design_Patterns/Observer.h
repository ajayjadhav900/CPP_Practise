#include <string>
#include<vector>
using namespace std;

class Icustomer
{

public:
    virtual void update(string msg_from_amazon) = 0;
};
class customerPrime : public Icustomer
{
public:
    string name;
    void update(string msg_from_amazon);
    customerPrime(const string &str)
    {
        name = str;
    }
};

class Publisher
{
    public:
    bool Imp_update;

    /// @brief prime list
    vector <customerPrime> PrimeList;
    void add_customers(const customerPrime &P);
    void remover_customers();
    void notify_customers();
    void business_logic();

};