#include <iostream>
#include "ParkingAdmin.hpp"

/*

https://github.com/tssovi/grokking-the-object-oriented-design-interview/blob/master/object-oriented-design-case-studies/design-a-parking-lot.md

g++ -g -o parking_management ParkingSlot.cpp ParkingLot.cpp Vehicle.cpp Payment.cpp Ticket.cpp
 ParkingDisplayDashboard.cpp ParkingAdmin.cpp ParkingAttendant.cpp main.cpp
*/

/*Next assignment : multiple entry points and exit points Admin should create entry ponits and exit points accordingly exit and entry managers */
int main()
{
    ParkingDisplayDashboard Dashboard;
    ParkingAdmin admin;

    admin.GenerateParking();
    admin.GroundFloorParking.PrintParkingSlots();

    admin.GetEntryAttendant()->StartWorking();
    admin.ParkingAttendants[3]->StartWorking();


    return 0;
}
