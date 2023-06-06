#include "Ticket.hpp"

Ticket::Ticket(const std::string& ticketID, std::time_t currTime, int cost, ParkingSlot* tktSlot)
    : TicketID(ticketID), EntryTime(currTime), Cost(cost), TktSlot(tktSlot) {}
