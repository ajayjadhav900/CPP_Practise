#include <iostream>
#include <memory>
using namespace std;
class IRecoveryTypes
{
public:
    virtual void HandleRecovery() = 0;
    virtual ~IRecoveryTypes()
    {

        cout << "~ IRecoveryTypes()";
    }
};

class RevertVMRecovery : public IRecoveryTypes
{
public:
    void HandleRecovery()
    {
        cout << "HandleRecovery : RevertVMRecovery\n";
    }
};

class VMDisksRecovery : public IRecoveryTypes
{

public:
    void HandleRecovery()
    {
        cout << "HandleRecovery : VMDisksRecovery\n";
    }
};

class EmergencyRecovery : public IRecoveryTypes
{

public:
    void HandleRecovery()
    {
        cout << "HandleRecovery : EmergencyRecovery\n";
    }
};

class VMFileLevelREcovery : public IRecoveryTypes
{

public:
    void HandleRecovery()
    {
        cout << "HandleRecovery : VMFileLevelREcovery\n";
    }
};

class FactoryRecovery
{
public:
    unique_ptr<IRecoveryTypes> RecoveryType;
    char Type;

    virtual unique_ptr<IRecoveryTypes> CreateRecoveryObjects() = 0;
    virtual ~FactoryRecovery()
    {
        cout << "~ FactoryRecovery()";
    }
};

class RecoveryTypeCreator : public FactoryRecovery
{

public:
    RecoveryTypeCreator(char type)
    {
        Type = type;
    }
    unique_ptr<IRecoveryTypes> CreateRecoveryObjects()
    {
        if (Type == 'R')
        {
            return std::unique_ptr<IRecoveryTypes>(new RevertVMRecovery());
        }
        else if (Type == 'D')
        {
            return std::unique_ptr<IRecoveryTypes>(new VMDisksRecovery());
        }
        else if (Type == 'L')
        {
            return std::unique_ptr<IRecoveryTypes>(new VMFileLevelREcovery());
        }
        else if (Type == 'E')
        {
            return std::unique_ptr<IRecoveryTypes>(new EmergencyRecovery());
        }
        return std::move(RecoveryType);
    }
    ~RecoveryTypeCreator()
    {
        cout << "\n ~ RecoveryTypeCreator()";
    }
};

void Client(unique_ptr<FactoryRecovery> &fact)
{
    unique_ptr<IRecoveryTypes> recType = fact->CreateRecoveryObjects();
    recType->HandleRecovery();
}

int main()
{
    unique_ptr<FactoryRecovery> fact(new RecoveryTypeCreator('E'));
    Client(fact);
}