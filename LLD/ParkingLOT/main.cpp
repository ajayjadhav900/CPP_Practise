#include <iostream>
#include "ParkingManager.hpp"

int main() {
    EntryManager entryManager;
    ExitManager exitManager;

    // Example usage of the parking management system
    entryManager.AllocateParking();
/*
    // Get a free parking slot for a bike
    ParkingSlot* bikeSlot = entryManager.GetFreeParkingSlot(VehicleTypes::TWO_WHEELER);

    // Create a ticket for the bike
    entryManager.CreateTicket(bikeSlot);

    // Get the ticket details
    std::string ticketID = "123"; // Assuming a valid ticket ID
    Ticket* ticket = entryManager.GetTicketDetails(ticketID);

    if (ticket != nullptr) {
        // Perform operations with the ticket
        // For example, set the exit time and update the ticket details
        ticket->setExitTime();
        entryManager.UpdateTicketDetails(ticket);
    }

    // Perform exit operations
    exitManager.AllocateParking();

    // Get the ticket details at the exit
    Ticket* exitTicket = exitManager.GetTicketDetails(ticketID);

    if (exitTicket != nullptr) {
        // Perform operations with the ticket at the exit
        // For example, calculate the parking duration and print the details
        std::chrono::steady_clock::duration duration = exitTicket->getExitTime() - exitTicket->getEntryTime();
        long long parkingDuration = std::chrono::duration_cast<std::chrono::minutes>(duration).count();

        std::cout << "Ticket ID: " << exitTicket->getTicketID() << std::endl;
        std::cout << "Slot ID: " << exitTicket->getSlotID() << std::endl;
        std::cout << "Parking duration: " << parkingDuration << " minutes" << std::endl;
    }
*/
    return 0;
}