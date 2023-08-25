#include <memory>
#include "ParkingSlot.hpp"

class ParkingSlotFactory
{
public:
    static std::shared_ptr<ParkingSlot> CreateParkingSlot(const std::string &id, VehicleTypes type, bool occupied, int floorNo);
};

// In ParkingSlot.cpp
std::shared_ptr<ParkingSlot> ParkingSlotFactory::CreateParkingSlot(const std::string &id, VehicleTypes type, bool occupied, int floorNo)
{
    std::shared_ptr<ParkingSlot> slot;
    if (type == VehicleTypes::TWO_WHEELER)
    {
        std::shared_ptr<ParkingSlot> slot(new BikeParkingSlot(id, occupied, floorNo));
        return slot;
    }
    else if (type == VehicleTypes::FOUR_WHEELER)
    {
        std::shared_ptr<ParkingSlot> slot(new CarParkingSlot(id, occupied, floorNo));
        return slot;
    }
    else if (type == VehicleTypes::TRUCK)
    {
        std::shared_ptr<ParkingSlot> slot(new TruckParkingSlot(id, occupied, floorNo));
        return slot;
    }
    else
    {
        return nullptr; // Handle invalid type
    }
    return slot;
}
