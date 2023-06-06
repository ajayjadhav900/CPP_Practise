#include "ParkingManager.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>
#include<chrono>
void ParkingManager::GenerateParking() {
    AllParkingVec.push_back(BikeParkingSlot("B1A", false));
    AllParkingVec.push_back(BikeParkingSlot("B1B", false));
    AllParkingVec.push_back(BikeParkingSlot("B1C", false));
    AllParkingVec.push_back(BikeParkingSlot("B1D", false));
    AllParkingVec.push_back(BikeParkingSlot("B1E", false));

    AllParkingVec.push_back(CarParkingSlot("C1A", false));
    AllParkingVec.push_back(CarParkingSlot("C1B", false));
    AllParkingVec.push_back(CarParkingSlot("C1C", false));
    AllParkingVec.push_back(CarParkingSlot("C1D", false));
    AllParkingVec.push_back(CarParkingSlot("C1E", false));
}

ParkingManager::ParkingManager() {
    GenerateParking();
}

ParkingSlot* EntryManager::GetFreeParkingSlot(VehicleTypes type) {
    ParkingSlot* newSlot = nullptr;
    if (type == VehicleTypes::TWO_WHEELER) {
        newSlot = &AllParkingVec[0];
    }
    else if (type == VehicleTypes::FOUR_WHEELER) {
        newSlot = &AllParkingVec[5];
    }
    else {
        std::cout << "Invalid vehicle type!!! \n";
    }
    return newSlot;
}
/*
Vehicle* EntryManager::CreateVehicle(VehicleTypes type) {
    Vehicle* newVeh = nullptr;
    if (type == VehicleTypes::TWO_WHEELER) {
        newVeh = new Bike("MH14GF1759", VehicleTypes::TWO_WHEELER);
    }
    else if (type == VehicleTypes::FOUR_WHEELER) {
        newVeh = new Car("MH14GN8429", VehicleTypes::FOUR_WHEELER);
    }
    return newVeh;
}
*/
void EntryManager::CreateTicket(ParkingSlot* parkSlot) {
    auto currentTime = std::chrono::system_clock::now();
    std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);
    Ticket* tkt = new Ticket("TKT1", currentTimeT, 10, parkSlot);
    AllTicketsList.push_back(tkt);
}

void EntryManager::AllocateParking()
{
}

Ticket *EntryManager::GetTicketDetails(const std::string &id)
{
    return nullptr;
}

void EntryManager::UpdateTicketDetails(Ticket *ticket)
{
}

Ticket* ExitManager::GetTicketDetails(const std::string& id) {
    return AllTicketsList[0];
}

void ExitManager::UpdateTicketDetails(Ticket* ticket) {
    ticket->Cost = 20;
}

void ExitManager::AllocateParking()
{
}

void ExitManager::CreateTicket(ParkingSlot *parkSlot)
{
}

ParkingSlot *ExitManager::GetFreeParkingSlot(VehicleTypes type)
{
    return nullptr;
}
