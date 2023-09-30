#include "TicketCounter.h"
#include <iostream>

TicketCounter::TicketCounter(int id, int customer, int hall, const std::string& movie, float price)
    : ticketId(id), customerId(customer), hallId(hall), movieName(movie), ticketPrice(price) {}

void TicketCounter::ShowTickets() {
    // Implementation for showing available tickets
    // ...
}

void TicketCounter::BookTickets() {
    // Implementation for booking tickets
    // ...
}
