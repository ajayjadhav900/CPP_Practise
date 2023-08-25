#include <iostream>
#include "ParkingAdmin.hpp"
#include "ParkingAttendant.hpp"
#include "ParkingDisplayDashboard.hpp"


/*

https://github.com/tssovi/grokking-the-object-oriented-design-interview/blob/master/object-oriented-design-case-studies/design-a-parking-lot.md

g++ -g -o parking_management ParkingSlot.cpp ParkingLot.cpp Vehicle.cpp Payment.cpp Ticket.cpp
ParkingAdmin.cpp ParkingAttendant.cpp ParkingDisplayDashboard.cpp main.cpp*/

int main()
{
    ParkingAdmin admin;
    admin.GenerateParking();
    admin.GroundFloorParking.PrintParkingSlots();
    ParkingDisplayDashboard Dashboard(admin.GroundFloorParking);

    EntryManager entryManager(admin.GroundFloorParking, Dashboard);
    entryManager.StartWorking();
    ExitManager exitManager(admin.GroundFloorParking);

    exitManager.AllTicketsList = entryManager.AllTicketsList;

    exitManager.StartWorking();

    return 0;
}
