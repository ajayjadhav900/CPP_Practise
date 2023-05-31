class Handler
{
    public:
    Handler *Successor;
    void SetSuccessor(Handler *successor)
    {
        Successor = successor;
    }
    void virtual HandleRequest(int req) = 0;
};

class ConcreteHandle1 : public Handler
{
    public:

    void  HandleRequest(int req );
};

class ConcreteHandle2 : public Handler
{
    public:

    void  HandleRequest(int req );
};

class ConcreteHandle3 : public Handler
{
    public:

    void  HandleRequest(int req );
};