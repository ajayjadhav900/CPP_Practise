#include "ParkingSlot.hpp"
#include <iostream>
#include <string>
using namespace std;
// ParkingSlot implementation

ParkingSlot::ParkingSlot(const std::string &id, bool occupied, int floorNo)
    : slotID(id), isOccupied(occupied), FloorNo(floorNo) {}

ParkingSlot::~ParkingSlot() {}

void ParkingSlot::parkVehicle()
{
    if (!isOccupied)
    {
        isOccupied = true;
        std::cout << "Vehicle with type parked in slot " << static_cast<int>(getVehicleType()) << slotID << std::endl;
    }
    else
    {
        std::cout << "Slot " << slotID << " is already occupied" << std::endl;
    }
}

// BikeParkingSlot implementation

BikeParkingSlot::BikeParkingSlot(const std::string &id, bool occupied, int floorNo)
    : ParkingSlot(id, occupied, floorNo) {}

VehicleTypes BikeParkingSlot::getVehicleType() const
{
    return VehicleTypes::TWO_WHEELER;
}

string BikeParkingSlot::GetSlotID()
{
    return slotID;
}

bool BikeParkingSlot::IsOccupied()
{
    return isOccupied;
}

void ParkingSlot::releaseSlot()
{
    if (isOccupied)
    {
        isOccupied = false;
        std::cout << "Vehicle released from slot " << slotID << std::endl;
    }
    else
    {
        std::cout << "Slot " << slotID << " is already vacant" << std::endl;
    }
}

// CarParkingSlot implementation

CarParkingSlot::CarParkingSlot(const std::string &id, bool occupied, int floorNo)
    : ParkingSlot(id, occupied, FloorNo) {}

VehicleTypes CarParkingSlot::getVehicleType() const
{
    return VehicleTypes::FOUR_WHEELER;
}

string CarParkingSlot::GetSlotID()
{
    return slotID;
}

bool CarParkingSlot::IsOccupied()
{
    return isOccupied;
}

TruckParkingSlot::TruckParkingSlot(const std::string &id, bool occupied, int floorNo)
    : ParkingSlot(id, occupied, floorNo)
{
}

VehicleTypes TruckParkingSlot::getVehicleType() const
{
    return VehicleTypes::TRUCK;
}

string TruckParkingSlot::GetSlotID()
{
    return slotID;
}

bool TruckParkingSlot::IsOccupied()
{
    return isOccupied;
}
