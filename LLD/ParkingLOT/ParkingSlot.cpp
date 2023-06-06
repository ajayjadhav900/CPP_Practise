#include "ParkingSlot.hpp"

ParkingSlot::ParkingSlot(const std::string& id, bool occupied) : slotID(id), isOccupied(occupied) {}

BikeParkingSlot::BikeParkingSlot(const std::string& id, bool occupied) : ParkingSlot(id, occupied) {}

CarParkingSlot::CarParkingSlot(const std::string& id, bool occupied) : ParkingSlot(id, occupied) {}
