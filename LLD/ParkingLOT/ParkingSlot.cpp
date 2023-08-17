#include "ParkingSlot.hpp"
#include <iostream>

// ParkingSlot implementation

ParkingSlot::ParkingSlot(const std::string &id, bool occupied)
    : slotID(id), isOccupied(occupied) {}

ParkingSlot::~ParkingSlot() {}

void ParkingSlot::parkVehicle()
{
    if (!isOccupied)
    {
        isOccupied = true;
        std::cout << "Vehicle with type parked in slot "<<static_cast<int>(getVehicleType()) << slotID << std::endl;
    }
    else
    {
        std::cout << "Slot " << slotID << " is already occupied" << std::endl;
    }
}

// BikeParkingSlot implementation

BikeParkingSlot::BikeParkingSlot(const std::string &id, bool occupied)
    : ParkingSlot(id, occupied) {}

VehicleTypes BikeParkingSlot::getVehicleType() const
{
    return VehicleTypes::TWO_WHEELER;
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

CarParkingSlot::CarParkingSlot(const std::string &id, bool occupied)
    : ParkingSlot(id, occupied) {}

VehicleTypes CarParkingSlot::getVehicleType() const
{
    return VehicleTypes::FOUR_WHEELER;
}


TruckParkingSlot::TruckParkingSlot(const std::string &id, bool occupied)
    : ParkingSlot(id, occupied)
{
}
