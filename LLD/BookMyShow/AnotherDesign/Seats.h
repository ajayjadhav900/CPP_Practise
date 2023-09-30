#ifndef SEATS_H
#define SEATS_H

#include <string>

class Seats {
private:
    int seatId;
    int hallId;
    std::string seatType;
    int totalSeats;
    int seatsBooked;

public:
    Seats(int id, int hall, const std::string& type, int total, int booked);
    void DisplayAvailableSeats();
};

#endif  // SEATS_H
