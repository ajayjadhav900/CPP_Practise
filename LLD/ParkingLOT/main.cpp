#include <iostream>
#include "ParkingManager.hpp"
/*
g++ -g -o parking_management ParkingSlot.cpp Payment.cpp Ticket.cpp ParkingManager.cpp vehicle.cpp main.cpp
*/
int main()
{
    EntryManager entryManager;
    ExitManager exitManager;

    // Example usage of the parking management system
    entryManager.AllocateParking();

    // Get a free parking slot for a bike
    ParkingSlot *bikeSlot = entryManager.GetFreeParkingSlot(VehicleTypes::TWO_WHEELER);

    // Create a ticket for the bike
    Car bk("MH14 GN8617", VehicleTypes::FOUR_WHEELER);
    Vehicle &veh = bk;
    entryManager.CreateTicket(bikeSlot, veh);

    // Get the ticket details
    std::string ticketID = "TKT1"; // Assuming a valid ticket ID
    Ticket *ticket = entryManager.GetTicketDetails(ticketID);
    std::cout << "Ticket Status: " << static_cast<int>(ticket->GetStatus()) << std::endl;
    if (ticket != nullptr)
    {
        // Perform operations with the ticket
        // For example, set the exit time and update the ticket details
        ticket->setExitTime();
        entryManager.UpdateTicketDetails(ticket);
    }
    entryManager.AllocateParking();
    exitManager.AllTicketsList = entryManager.AllTicketsList;
    // Perform exit operations
    exitManager.AllParkingVec = entryManager.AllParkingVec;
    // Get the ticket details at the exit
    Ticket *exitTicket = exitManager.GetTicketDetails(ticketID);
    if (exitTicket != nullptr)
    {
        // Perform operations with the ticket at the exit
        // For example, calculate the parking duration and print the details
        std::chrono::steady_clock::duration duration = exitTicket->getExitTime() - exitTicket->getEntryTime();
        long long parkingDuration = std::chrono::duration_cast<std::chrono::minutes>(duration).count();

        std::cout << "Ticket ID: " << exitTicket->getTicketID() << std::endl;
        std::cout << "Ticket Status: " << static_cast<int>(ticket->GetStatus()) << std::endl;
        std::cout << "Slot ID: " << exitTicket->getSlotID() << std::endl;
        std::cout << "Vehile Reg no: " << exitTicket->GetVehicleData().RegNo.c_str();
        VehicleTypes type = exitTicket->GetVehicleData().Type;
        std::cout << " Vehicle Type: " << static_cast<int>(type) << std::endl;
        std::cout << "Parking duration: " << parkingDuration << " minutes" << std::endl;
        std::cout << "Cost of ticket: " << exitTicket->EstimateCost() << " rupees" << std::endl;
        std::cout << "Payment: " << std::endl;
        exitTicket->DoThePayment(PaymentMode::ONLINEAPP, exitTicket->EstimateCost());
    }
    auto slot = exitManager.GetTheParkingSlot("B1");
    slot->releaseSlot();

    return 0;
}
