#include <iostream>
#include <random>
#include "ParkingAdmin.hpp"

/*

https://github.com/tssovi/grokking-the-object-oriented-design-interview/blob/master/object-oriented-design-case-studies/design-a-parking-lot.md

g++ -g -o parking_management ParkingSlot.cpp ParkingLot.cpp Vehicle.cpp Payment.cpp Ticket.cpp
 ParkingDisplayDashboard.cpp ParkingAdmin.cpp ParkingAttendant.cpp main.cpp
*/

/* Next assignment : multiple entry points and exit points
 Admin should create entry ponits and exit points accordingly exit and entry managers */
int main()
{
    ParkingDisplayDashboard Dashboard;
    ParkingAdmin admin;

    admin.GenerateParking();
    admin.GroundFloorParking.PrintParkingSlots();

    int noofTime = 3;
    int k = 4;

    // Set up random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disA(0, 2); // For generating random values for GetEntryAttendant
    std::uniform_int_distribution<> disB(3, 4); // For generating random values for GetExitAttendant

    for (int i = 0; i < noofTime; ++i)
    {
        if (i == 0 || disA(gen) == 0)
        {
            std::cout << "Vehicle arrives at GateNo: " << k;
            admin.GetEntryAttendant()->StartWorking(k);
        }
        if (disB(gen) == 3 || disB(gen) == 4)
        {
            std::cout << "Vehicle departed from GateNo: " << k;
            admin.GetExitAttendant()->StartWorking(k);
        }
    }

    return 0;
}
