#ifndef PARKINGSLOT_HPP
#define PARKINGSLOT_HPP

#include <string>

enum class VehicleTypes { TWO_WHEELER, FOUR_WHEELER , TRUCK};

class ParkingSlot {
public:
    std::string slotID;
    bool isOccupied;

    ParkingSlot(const std::string& id, bool occupied);
    virtual ~ParkingSlot();  // Virtual destructor to allow proper cleanup in derived classes

    virtual VehicleTypes getVehicleType() const = 0;  // Pure virtual function, to be overridden in derived classes
    virtual void parkVehicle();  // Pure virtual function, to be overridden in derived classes
    virtual void releaseSlot();  // Pure virtual function, to be overridden in derived classes
};

class BikeParkingSlot : public ParkingSlot {
public:
    BikeParkingSlot(const std::string& id, bool occupied);

    VehicleTypes getVehicleType() const override;
};

class CarParkingSlot : public ParkingSlot {
public:
    CarParkingSlot(const std::string& id, bool occupied);

    VehicleTypes getVehicleType() const override;
};

class TruckParkingSlot: public ParkingSlot
{
    public:
    TruckParkingSlot(const std::string &id, bool occupied);

};
#endif
