#include <iostream>
#include"Factory.hpp"
using namespace std;

class WindowsButton : public Button
{

public:
    WindowsButton()
    {
        cout << "I am a WindowsButton" << endl;
    }
    ~WindowsButton()
    {
        cout << "WindowsButton Button destructor \n";
    }
    void render();
    void click();
};

void WindowsButton::click()
{

    cout << " I am a windows Button Click" << endl;
}
void WindowsButton::render()
{
    cout << " I am a windows Button Render" << endl;
}
class RadioButton : public Button
{

public:
    RadioButton()
    {
        cout << "I am a RadioButton" << endl;
    }
    void render();
    void click();
};
void RadioButton::click()
{

    cout << " I am a RadioButton  Click" << endl;
}
void RadioButton::render()
{
    cout << " I am a RadioButton  Render" << endl;
}

class HTMLButton : public Button
{

public:
    HTMLButton()
    {
        cout << "I am a HTMLButton" << endl;
    }
    void render();
    void click();
};
void HTMLButton::click()
{

    cout << " I am a HTML Button Click" << endl;
}
void HTMLButton::render()
{
    cout << " I am a HTML Button Render" << endl;
}
class Dialog
{
public:
    virtual Button *CreateButton() = 0;
    ~Dialog()
    {
        cout << "Destructor Dialog\n";
    }
    std::string SomeOperation()
    {
        // Call the factory method to create a Product object.
        Button *Bt = this->CreateButton();
        // Now, use the product.
        std::string result = "Creator: The same creator's code has just worked with";
        delete Bt;
        return result;
    }
};

class CreateWindowsButton : public Dialog
{
    ~CreateWindowsButton()
    {
        cout << "CreateWindowsButton Dialog\n";
    }

    Button *CreateButton()
    {
        Button *bp = new WindowsButton();
        bp->click();
        bp->render();
        return bp;
    }
};

class CreateHTMLButton : public Dialog
{
    Button *CreateButton()
    {
        Button *bp = new HTMLButton();
        bp->click();
        bp->render();
        return bp;
    }
};

class CreateRadioButton : public Dialog
{

    Button *CreateButton()
    {
        Button *bp = new RadioButton();
        bp->click();
        bp->render();
        return bp;
    }
};
int main()
{

    cout << "factory" << endl;
    Dialog *CWB = new CreateWindowsButton();
    CWB->SomeOperation();
    delete CWB;
    return 0;
}