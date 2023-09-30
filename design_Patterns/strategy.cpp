#include <iostream>
using namespace std;

class RouteStrategy
{

public:
    virtual void BuildStrategy() = 0;
    virtual void CalculateDistance() = 0;
    virtual ~RouteStrategy()
    {
    }
};
class RoadStrategy : public RouteStrategy
{
public:
    void BuildStrategy() override
    {
        std::cout << "This is RoadStrategy.\n";
    }
    void CalculateDistance() override
    {
        std::cout << " This is calculation time algo for RoadStrategy. \n";
    }
};
class WalkingStrategy : public RouteStrategy
{
public:
    void BuildStrategy() override
    {
        std::cout << "This is WalkingStrategy.\n";
    }
    void CalculateDistance() override
    {
        std::cout << " This is calculation time algo for WalkingStrategy. \n";
    }
};

class PublicTransportStrategy : public RouteStrategy
{
public:
    void BuildStrategy() override
    {
        std::cout << "This is PublicTransportStrategy.\n";
    }
    void CalculateDistance() override
    {
        std::cout << " This is calculation time algo for PublicTransportStrategy. \n";
    }
};

class Nevigator
{

    RouteStrategy *UserRouteStrategy;

public:
    void SetRouteStrategy(RouteStrategy *userRouteStrategy)
    {
        UserRouteStrategy = userRouteStrategy;
    }
    void ExecuteTheStrategy()
    {
        UserRouteStrategy->BuildStrategy();
    }
    void ExecuteTheDistanceCalculationAlgo()
    {
        UserRouteStrategy->CalculateDistance();
    }
    void DoSomethingBusinessLogic()
    {
        if (UserRouteStrategy)
        {
            ExecuteTheStrategy();
            ExecuteTheDistanceCalculationAlgo();
        }
        else
        {
            cout << "Invalid Stratgy!!!\n";
        }
    }
};

void DriveTheTrasportationStrategies(RouteStrategy *routes)
{
    Nevigator nv; // this is a context maintains a reference to one of the strategy
    // objects. The context doesn't know the concrete class of a
    // strategy. It should work with all strategies via the
    // strategy interface.
    nv.SetRouteStrategy(routes); // strategy can be switched at runtime.

    nv.DoSomethingBusinessLogic();
}
int main()
{
    RouteStrategy *routes = new PublicTransportStrategy(); // strategy 1
    DriveTheTrasportationStrategies(routes);

    routes = new RoadStrategy(); // strategy 2
    DriveTheTrasportationStrategies(routes);

    routes = new WalkingStrategy(); // strategy 3
    DriveTheTrasportationStrategies(routes);
    
    return 0;
}