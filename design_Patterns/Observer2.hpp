
#include <vector>
#include <string>
using namespace std;

class IInvestor
{
public:
    void virtual update(double) = 0;
};
class Stock
{
public:
    vector<IInvestor *> investors;
    string Name;
    double Price;
    Stock(const std::string &name, double initialPrice) : Name(name), Price(initialPrice) {}

    void virtual attach(IInvestor *);
    void virtual detach(IInvestor *);
    void virtual notifyInvestors(double);
    void virtual setPrice(double);
};

class IBM : public Stock
{
public:
    IBM(const std::string &name, double initialPrice) : Stock(name, initialPrice) {}
};

class Investor : public IInvestor
{
    string Name;

public:
    Investor(string name)
    {
        Name = name;
    }
    void update(double price);
};