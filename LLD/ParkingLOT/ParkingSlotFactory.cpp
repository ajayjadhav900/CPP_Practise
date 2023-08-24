#include "ParkingSlot.hpp"
class ParkingSlotFactory
{
public:
    static ParkingSlot *CreateParkingSlot(const std::string &id, VehicleTypes type, bool occupied, int floorNo);
};

// In ParkingSlot.cpp
ParkingSlot *ParkingSlotFactory::CreateParkingSlot(const std::string &id, VehicleTypes type, bool occupied, int floorNo)
{
    if (type == VehicleTypes::TWO_WHEELER)
    {
        return new BikeParkingSlot(id, occupied, floorNo);
    }
    else if (type == VehicleTypes::FOUR_WHEELER)
    {
        return new CarParkingSlot(id, occupied, floorNo);
    }
    else if (type == VehicleTypes::TRUCK)
    {
        return new TruckParkingSlot(id, occupied, floorNo);
    }
    else
    {
        return nullptr; // Handle invalid type
    }
}
