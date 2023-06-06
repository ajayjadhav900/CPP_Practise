#ifndef PARKINGSLOT_HPP
#define PARKINGSLOT_HPP

#include <string>

enum class VehicleTypes { TWO_WHEELER, FOUR_WHEELER };

class ParkingSlot {
public:
    std::string slotID;
    bool isOccupied;
    ParkingSlot(const std::string& id, bool occupied);
};

class BikeParkingSlot : public ParkingSlot {
public:
    BikeParkingSlot(const std::string& id, bool occupied);
};

class CarParkingSlot : public ParkingSlot {
public:
    CarParkingSlot(const std::string& id, bool occupied);
};

#endif
