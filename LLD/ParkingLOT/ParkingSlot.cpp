#include "ParkingSlot.hpp"
#include <iostream>

// ParkingSlot implementation

ParkingSlot::ParkingSlot(const std::string& id, bool occupied)
    : slotID(id), isOccupied(occupied) {}

ParkingSlot::~ParkingSlot() {}

// BikeParkingSlot implementation

BikeParkingSlot::BikeParkingSlot(const std::string& id, bool occupied)
    : ParkingSlot(id, occupied) {}

VehicleTypes BikeParkingSlot::getVehicleType() const {
    return VehicleTypes::TWO_WHEELER;
}

void BikeParkingSlot::parkVehicle() {
    if (!isOccupied) {
        isOccupied = true;
        std::cout << "Bike parked in slot " << slotID << std::endl;
    } else {
        std::cout << "Slot " << slotID << " is already occupied" << std::endl;
    }
}

void BikeParkingSlot::releaseSlot() {
    if (isOccupied) {
        isOccupied = false;
        std::cout << "Bike released from slot " << slotID << std::endl;
    } else {
        std::cout << "Slot " << slotID << " is already vacant" << std::endl;
    }
}

// CarParkingSlot implementation

CarParkingSlot::CarParkingSlot(const std::string& id, bool occupied)
    : ParkingSlot(id, occupied) {}

VehicleTypes CarParkingSlot::getVehicleType() const {
    return VehicleTypes::FOUR_WHEELER;
}

void CarParkingSlot::parkVehicle() {
    if (!isOccupied) {
        isOccupied = true;
        std::cout << "Car parked in slot " << slotID << std::endl;
    } else {
        std::cout << "Slot " << slotID << " is already occupied" << std::endl;
    }
}

void CarParkingSlot::releaseSlot() {
    if (isOccupied) {
        isOccupied = false;
        std::cout << "Car released from slot " << slotID << std::endl;
    } else {
        std::cout << "Slot " << slotID << " is already vacant" << std::endl;
    }
}
