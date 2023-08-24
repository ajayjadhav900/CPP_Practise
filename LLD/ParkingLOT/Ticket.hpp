#ifndef TICKET_HPP
#define TICKET_HPP


#include <string>
#include <chrono>
#include "Vehicle.hpp"
#include "Payment.hpp"
enum class TicketStatus
{
    IDLE,
    ACTIVE,
    PAID
};
class Ticket {
public:
    Ticket(const std::string& slotID, Vehicle parkVehicle);

    std::string getTicketID() const;
    std::string getSlotID() const;
    std::chrono::steady_clock::time_point getEntryTime() const;
    std::chrono::steady_clock::time_point getExitTime() const;
    double getExitTimeinSecs () const;
    Vehicle & GetVehicleData();
    void setExitTime();
    int EstimateCost();
    void DoThePayment(PaymentMode mode, int amt);
    void SetStatus(char ch);
    TicketStatus GetStatus();
private:
    std::string ticketID;
    std::string slotID;
    std::chrono::steady_clock::time_point entryTime;
    std::chrono::steady_clock::time_point exitTime;
    double exitTimeInSeconds;
    Vehicle ParkVehicle;
    int cost;
    TicketStatus Status;
    IPayment *Pay;

};

#endif
