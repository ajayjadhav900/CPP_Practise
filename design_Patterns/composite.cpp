#include <vector>
#include <string>
#include <iostream>
#include"composite.hpp"
using namespace std;



class OrderBox : public IItem
{
public:
    int Price;
    string Name;
    vector<IItem *> Items;

    OrderBox(string name, int price, vector<IItem *> items)
    {
        Name = name;
        Price = price;
        Items = items;
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
        for (auto itr : Items)
        {
            cout << "Item Name: " << itr->nameofItem() << " Price: " << itr->PriceOftheItem() << endl;
        }
    }
};

int main()
{
    IItem *it1 = new Item("HeadPhone", 2000);
    IItem *it2 = new Item("ScreenGuard", 1000);
    IItem *it3 = new Item("Nanpro", 700);
    IItem *it4 = new Item("Phone", 78000);

    vector<IItem *> items;
    items.push_back(it1);
    items.push_back(it2);
    items.push_back(it3);
    items.push_back(it4);

    IItem *order = new OrderBox("Standard Order", 100, items);


        order->printDetails();


    // Clean up dynamically allocated memory
    delete it1;
    delete it2;
    delete it3;
    delete it4;
    delete order;

    return 0;
}
