#include "Vehicle.hpp"

Bike::Bike(std::string regNO, VehicleTypes type)
{
    RegNo = regNO;
    Type = type;
}
Car::Car(std::string regNO, VehicleTypes type)
{
    RegNo = regNO;
    Type = type;
}
/*
void Vehicle::SetVehicle(std::string regno, VehicleTypes type)
{
    RegNo = regno;
    Type = type;
}
*/