#include <string>
enum class VehicleTypes
{
    TWO_WHEELER,
    FOUR_WHEELER
};
class Vehicle
{
public:
    std::string RegNo;
    VehicleTypes Type;
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