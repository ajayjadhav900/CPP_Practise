#ifndef PARKINGSLOT_HPP
#define PARKINGSLOT_HPP

#include <string>
using namespace std;
enum class VehicleTypes { TWO_WHEELER, FOUR_WHEELER , TRUCK};

class ParkingSlot {
public:
    std::string slotID;
    bool isOccupied;
    int FloorNo;

    ParkingSlot(const std::string& id, bool occupied, int floorNo);
    virtual ~ParkingSlot();  // Virtual destructor to allow proper cleanup in derived classes

    virtual VehicleTypes getVehicleType() const = 0;  // Pure virtual function, to be overridden in derived classes
    virtual void parkVehicle();  // Pure virtual function, to be overridden in derived classes
    virtual void releaseSlot();  // Pure virtual function, to be overridden in derived classes
    virtual string GetSlotID() = 0;
    virtual bool IsOccupied() = 0;
};

class BikeParkingSlot : public ParkingSlot {
public:
    BikeParkingSlot(const std::string& id, bool occupied, int floorNo);

    VehicleTypes getVehicleType() const override;
    virtual string GetSlotID();
    virtual bool IsOccupied();
};

class CarParkingSlot : public ParkingSlot {
public:
    CarParkingSlot(const std::string& id, bool occupied, int floorno);

    VehicleTypes getVehicleType() const override;
    virtual string GetSlotID();
    virtual bool IsOccupied();
};

class TruckParkingSlot: public ParkingSlot
{
    public:
    TruckParkingSlot(const std::string &id, bool occupied, int floorno);
    VehicleTypes getVehicleType() const override;
    virtual string GetSlotID();
    virtual bool IsOccupied();

};
#endif
