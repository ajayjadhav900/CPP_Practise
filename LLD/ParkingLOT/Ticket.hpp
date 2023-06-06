#include <string>
#include <chrono>
#include  "ParkingSlot.hpp"
class Ticket
{
    public:
    std::string TicketID;
    std::time_t EntryTime;
    int Cost;
    ParkingSlot *TktSlot;
    Ticket(std::string ticketID, std::time_t currTime, int cost, ParkingSlot *tktSlot);
};