
#include "Controller.hpp"
int main()
{
    Controller MainCon;
    MainCon.FirstLift.ElevatorCarCurrentPosition();

    ExternalDispatcher ext;
    ext.PressExternalButton(0);
    MainCon.FirstLift.PressInternalButton(4);

    ext.PressExternalButton(2);
    MainCon.FirstLift.PressInternalButton(0);
    return 0;
}