#include <string>
#include "ParkingSlot.hpp"

class Vehicle
{
public:
    std::string RegNo;
    VehicleTypes Type;
    //void SetVehicle(std::string regno, VehicleTypes type);
};
class Bike : public Vehicle
{
public:
    Bike(std::string regNO, VehicleTypes type);
};
class Car : public Vehicle
{
public:
    Car(std::string regNO, VehicleTypes type);
};