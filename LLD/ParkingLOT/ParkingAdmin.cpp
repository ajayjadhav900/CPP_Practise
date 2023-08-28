#include "ParkingAdmin.hpp"
#include <iostream>
#include <memory>
ParkingAdmin::ParkingAdmin() : Dashboard(GroundFloorParking)
{
    AllTicketsList.clear();
    int k = 0;
    for (int i = 0; i < NoofEntryPoints; ++i)
    {
        ParkingAttendants.insert(std::make_pair(k, std::make_shared<EntryManager>(GroundFloorParking, Dashboard, AllTicketsList,k)));
    }
    int m = 3;
    for (int i = 0; i < NoofExitPoints; ++i)
    {
        ParkingAttendants.insert(std::make_pair(m, std::make_shared<ExitManager>(GroundFloorParking, AllTicketsList,m)));
        m++;
    }
}

ParkingAdmin::~ParkingAdmin()
{
    for (Ticket *tkts : AllTicketsList)
    {
        delete tkts;
    }
    AllTicketsList.clear();
}

void ParkingAdmin::GenerateParking()
{
    GroundFloorParking.GenerateParking();
}

void ParkingAdmin::assignParkingLotToDashboard(GroundFloor &groundFloorParking)
{
}

shared_ptr<ParkingAttendant> ParkingAdmin::GetEntryAttendant()
{
    shared_ptr<EntryManager> entryManagerPtr = std::dynamic_pointer_cast<EntryManager>(ParkingAttendants[0]);

    if (entryManagerPtr)
    {
        return entryManagerPtr;
    }
    else
    {
        std::cout << "\nError failed on Dynamic cast!!!\n";
        return nullptr;
    }
}

shared_ptr<ParkingAttendant> ParkingAdmin::GetExitAttendant()
{
    shared_ptr<ExitManager> exitManagerPtr = std::dynamic_pointer_cast<ExitManager>(ParkingAttendants[3]);

    if (exitManagerPtr)
    {
        return exitManagerPtr;
    }
    else
    {
        std::cout << "\nError failed on Dynamic cast!!!\n";
        return nullptr;
    }

    return ParkingAttendants[3];
}