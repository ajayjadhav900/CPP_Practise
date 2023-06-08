#ifndef TICKET_HPP
#define TICKET_HPP

#include <string>
#include <chrono>

class Ticket {
public:
    Ticket(const std::string& slotID);

    std::string getTicketID() const;
    std::string getSlotID() const;
    std::chrono::steady_clock::time_point getEntryTime() const;
    std::chrono::steady_clock::time_point getExitTime() const;

    void setExitTime();

private:
    std::string ticketID;
    std::string slotID;
    std::chrono::steady_clock::time_point entryTime;
    std::chrono::steady_clock::time_point exitTime;
};

#endif
