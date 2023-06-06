#ifndef TICKET_HPP
#define TICKET_HPP

#include <string>
#include <ctime>
#include "ParkingSlot.hpp"

class Ticket {
public:
    std::string TicketID;
    std::time_t EntryTime;
    int Cost;
    ParkingSlot* TktSlot;
    Ticket(const std::string& ticketID, std::time_t currTime, int cost, ParkingSlot* tktSlot);
};

#endif
