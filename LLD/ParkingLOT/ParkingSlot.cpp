/*
#include "ParkingSlot.hpp"

BikeParkingSlot::BikeParkingSlot(const std::string &id, bool isFree)
{
    ID = id;
    IsFree = isFree;
    //ParkedVehicle = parkedVehicle;
}

bool BikeParkingSlot::isEmpty()
{
    return true;
}

void BikeParkingSlot::BookParkingSlot()
{
    IsFree = false;
}

CarParkingSlot::CarParkingSlot(const std::string &id, bool isFree)
{
    ID = id;
    IsFree = isFree;
    //ParkedVehicle = parkedVehicle;
}

bool CarParkingSlot::isEmpty()
{
    return true;
}

void CarParkingSlot::BookParkingSlot()
{
    IsFree = false;
}
*/

#include "ParkingSlot.hpp"

ParkingSlot::ParkingSlot(const std::string& id, bool occupied) : slotID(id), isOccupied(occupied) {}

BikeParkingSlot::BikeParkingSlot(const std::string& id, bool occupied) : ParkingSlot(id, occupied) {}

CarParkingSlot::CarParkingSlot(const std::string& id, bool occupied) : ParkingSlot(id, occupied) {}

