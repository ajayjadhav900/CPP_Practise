#include "Seats.h"
#include <iostream>

Seats::Seats(int id, int hall, const std::string& type, int total, int booked)
    : seatId(id), hallId(hall), seatType(type), totalSeats(total), seatsBooked(booked) {}

void Seats::DisplayAvailableSeats() {
    // Implementation for displaying the available seats
    // ...
}
