
enum class PaymentMode
{
    CASH,
    ONLINEAPP,
    CARD
};
class IPayment
{

    public:
    void virtual PayingTheFee(int) = 0; 
};

class OnlineApp :public IPayment
{
    public:
    void PayingTheFee(int fee);
};

class Cash :public IPayment
{
    public:
    void PayingTheFee(int fee);
};

class Card :public IPayment
{
    public:
    void PayingTheFee(int fee); 
};


