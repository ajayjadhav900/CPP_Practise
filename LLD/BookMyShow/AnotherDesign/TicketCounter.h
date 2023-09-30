#ifndef TICKETCOUNTER_H
#define TICKETCOUNTER_H

#include <string>

class TicketCounter {
private:
    int ticketId;
    int customerId;
    int hallId;
    std::string movieName;
    float ticketPrice;

public:
    TicketCounter(int id, int customer, int hall, const std::string& movie, float price);
    void ShowTickets();
    void BookTickets();
};

#endif  // TICKETCOUNTER_H
