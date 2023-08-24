#include "Ticket.hpp"

Ticket::Ticket(const std::string &slotID, Vehicle parkVehicle)
    : slotID(slotID), entryTime(std::chrono::steady_clock::now())
{
    // Generate a unique ticket ID based on some logic
    // For simplicity, let's assume it's based on the current time
    ticketID = "TKT1";
    ParkVehicle = parkVehicle;
    Pay = nullptr;
    Status = TicketStatus::IDLE;
}

Ticket::~Ticket()
{
    delete Pay;
}

std::string Ticket::getTicketID() const
{
    return ticketID;
}

std::string Ticket::getSlotID() const
{
    return slotID;
}

std::chrono::steady_clock::time_point Ticket::getEntryTime() const
{
    return entryTime;
}

std::chrono::steady_clock::time_point Ticket::getExitTime() const
{
    return exitTime;
}

double Ticket::getExitTimeinSecs() const
{
    return exitTimeInSeconds;
}

Vehicle &Ticket::GetVehicleData()
{
    return ParkVehicle;
}

void Ticket::setExitTime()
{
    exitTime = std::chrono::steady_clock::now();
    // Calculate the exit time in seconds
    std::chrono::duration<double> elapsedTime = exitTime - std::chrono::steady_clock::time_point();
    exitTimeInSeconds = elapsedTime.count();

    // Add 10 minutes to the entry time
    std::chrono::minutes durationToAdd(10);
    exitTime += durationToAdd;
}

int Ticket::EstimateCost()
{
    if (ParkVehicle.Type == VehicleTypes::TWO_WHEELER)
    {
        cost = 20;
    }
    else if (ParkVehicle.Type == VehicleTypes::FOUR_WHEELER)
    {
        cost = 40;
    }
    return cost;
}

void Ticket::DoThePayment(PaymentMode mode, int amt)
{
    if (mode == PaymentMode::CASH)
    {
        Pay = new Cash();
        Pay->PayingTheFee(amt);
    }
    else if (mode == PaymentMode::ONLINEAPP)
    {
        Pay = new OnlineApp();
        Pay->PayingTheFee(amt);
    }
    else if (mode == PaymentMode::CARD)
    {
        Pay = new Card();
        Pay->PayingTheFee(amt);
    }
    else
    {
        Pay = nullptr;
    }
}

void Ticket::SetStatus(char choice)
{
    if (choice == 'A')
        Status = TicketStatus::ACTIVE;
    else if (choice == 'P')
        Status = TicketStatus::PAID;
}

TicketStatus Ticket::GetStatus()
{
    return Status;
}
