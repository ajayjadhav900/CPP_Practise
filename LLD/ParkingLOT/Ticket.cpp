#include "Ticket.hpp"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

Ticket::Ticket(const std::string &slotID,
               Vehicle parkVehicle,
               int entryGateNo)
    : slotID(slotID),
      EntryGateNo(entryGateNo),
      entryTime(std::chrono::steady_clock::now())
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random 5-digit number
    int randomNumber = std::rand() % 90000 + 10000;

    // Convert the random number to a string
    std::string randomString;
    std::stringstream ss;
    ss << randomNumber;
    ss >> randomString;

    ticketID = "TKT_" + randomString;
    ParkVehicle = parkVehicle;
    Status = TicketStatus::IDLE;
}

Ticket::~Ticket()
{
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
        Pay = std::make_unique<Cash>();
    }
    else if (mode == PaymentMode::ONLINEAPP)
    {
        Pay = std::make_unique<OnlineApp>();
    }
    else if (mode == PaymentMode::CARD)
    {
        Pay = std::make_unique<Card>();
    }
    else
    {
        Pay = nullptr;
    }
    if (Pay != nullptr)
        Pay->PayingTheFee(amt);
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

void Ticket::printParkingTicketDetails(Ticket *exitTicket)
{
    std::chrono::steady_clock::duration duration = exitTicket->getExitTime() - exitTicket->getEntryTime();
    long long parkingDuration = std::chrono::duration_cast<std::chrono::minutes>(duration).count();

    std::cout << "\n\n------ Parking Ticket ------" << std::endl;
    std::cout << "Ticket ID: " << exitTicket->getTicketID() << std::endl;
    std::cout << "Ticket Status: " << static_cast<int>(exitTicket->GetStatus()) << std::endl;
    std::cout << "Slot ID: " << exitTicket->getSlotID() << std::endl;
    std::cout << "Vehicle Reg no: " << exitTicket->GetVehicleData().RegNo;
    VehicleTypes type = exitTicket->GetVehicleData().Type;
    std::cout << " Vehicle Type: " << static_cast<int>(type) << std::endl;
    std::cout << "Parking duration: " << parkingDuration << " minutes" << std::endl;
    std::cout << "Cost of ticket: " << exitTicket->EstimateCost() << " rupees" << std::endl;
    std::cout << "Entry Gate No: " << exitTicket->EntryGateNo << std::endl;
    std::cout << "Exit Gate No: " << exitTicket->ExitGateNo << std::endl;
}