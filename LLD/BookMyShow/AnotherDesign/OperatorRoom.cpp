#include "OperatorRoom.hpp"
#include <iostream>

OperatorRoom::OperatorRoom(int id, const std::string& name, int hall)
    : inchargeId(id), inchargeName(name), hallId(hall) {}

void OperatorRoom::Control() {
    // Implementation for controlling the screen, movies, and sound systems
    // ...
}
