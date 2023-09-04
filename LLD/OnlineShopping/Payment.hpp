class IPayment
{
public:
    virtual void DoThePayment(int prize) = 0;
};

class DebitCard : public IPayment
{
public:
    void DoThePayment(int prize);
};
class CreditCard : public IPayment
{
public:
    void DoThePayment(int prize);
};
class UPIMode : public IPayment
{
public:
    void DoThePayment(int prize);
};
class COD : public IPayment
{
public:
    void DoThePayment(int prize);
};