class Button
{

public:
    Button()
    {
    }
    ~Button()
    {
        
    }
    virtual void render() = 0;
    virtual void click() = 0;
};