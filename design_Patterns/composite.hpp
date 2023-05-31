using namespace std;

class IItem
{
public:
    virtual std::string nameofItem() = 0;
    virtual int PriceOftheItem() = 0;
    virtual void printDetails() = 0;
};

class Item : public IItem
{
public:
    int Price;
    std::string Name;

    Item(string name, int price)
    {
        Name = name;
        Price = price;
    }

    string nameofItem() override
    {
        return Name;
    }

    int PriceOftheItem() override
    {
        return Price;
    }
    void printDetails() override
    {
                    cout << "Item Name: " << nameofItem() << " Price: " << PriceOftheItem() << endl;

    }
};