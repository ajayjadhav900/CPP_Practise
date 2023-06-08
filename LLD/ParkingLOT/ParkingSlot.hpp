#ifndef PARKINGSLOT_HPP
#define PARKINGSLOT_HPP

#include <string>

enum class VehicleTypes { TWO_WHEELER, FOUR_WHEELER };

class ParkingSlot {
public:
    std::string slotID;
    bool isOccupied;

    ParkingSlot(const std::string& id, bool occupied);
    virtual ~ParkingSlot();  // Virtual destructor to allow proper cleanup in derived classes

    virtual VehicleTypes getVehicleType() const = 0;  // Pure virtual function, to be overridden in derived classes
    virtual void parkVehicle() = 0;  // Pure virtual function, to be overridden in derived classes
    virtual void releaseSlot() = 0;  // Pure virtual function, to be overridden in derived classes
};

class BikeParkingSlot : public ParkingSlot {
public:
    BikeParkingSlot(const std::string& id, bool occupied);

    VehicleTypes getVehicleType() const override;
    void parkVehicle() override;
    void releaseSlot() override;
};

class CarParkingSlot : public ParkingSlot {
public:
    CarParkingSlot(const std::string& id, bool occupied);

    VehicleTypes getVehicleType() const override;
    void parkVehicle() override;
    void releaseSlot() override;
};

#endif
