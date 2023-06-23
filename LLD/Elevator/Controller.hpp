#include "ElevatorCar.hpp"
#include "ExternalDispatcher.hpp"
#include <vector>
class Controller
{
public:
    ElevatorCar FirstLift;
    ExternalDispatcher ExtDisp;
    std::vector<int> RequestedList;

public:
    Controller();
    void StartLift(int reqNo);
    void RequestFromExternalUser(int);
};
