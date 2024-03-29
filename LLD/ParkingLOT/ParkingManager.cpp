#include "ParkingManager.hpp"
#include <iostream>
using namespace std;
// ParkingManager implementation

void ParkingManager::GenerateParking()
{
    GroundFloorParking.GenerateParking();
    
    // Create and initialize the parking slots
    // Add more parking slots as needed
}

ParkingManager::ParkingManager()
{
    GenerateParking();
}

ParkingSlot *ParkingManager::GetTheParkingSlot(std::string slotid)
{
    for (ParkingSlot *slot : GroundFloorParking.AllParkingVec)
    {
        if (slot->slotID == slotid)
        {
            return slot;
        }
    }
    return nullptr;
}

// EntryManager implementation

ParkingSlot *EntryManager::GetFreeParkingSlot(VehicleTypes type)
{
    for (ParkingSlot *slot : GroundFloorParking.AllParkingVec)
    {
        if (!slot->isOccupied && slot->getVehicleType() == type)
        {
            slot->isOccupied= true;
            GroundFloorParking.currentParkSlots++;
            return slot;
        }
    }
    return nullptr;
}

void EntryManager::CreateTicket(ParkingSlot *parkSlot, const Vehicle &vehicle)
{
    if (parkSlot != nullptr)
    {
        Ticket *ticket = new Ticket(parkSlot->slotID, vehicle);
        AllTicketsList.push_back(ticket);
        parkSlot->parkVehicle();
        std::cout << "Ticket created for slot " << parkSlot->slotID << std::endl;
        std::cout << "Ticket ID: " << ticket->getTicketID() << std::endl;
    }
    else
    {
        std::cout << "No free parking slot available for the given vehicle type." << std::endl;
    }
}

void EntryManager::AllocateParking()
{
    // Implement the logic for allocating parking slots for incoming vehicles
    // You can use GetFreeParkingSlot() and CreateTicket() functions to allocate a slot and create a ticket, respectively.
}

Ticket *EntryManager::GetTicketDetails(const std::string &id)
{
    for (Ticket *ticket : AllTicketsList)
    {
        if (ticket->getTicketID() == id)
        {
            ticket->SetStatus('A');
            return ticket;
        }
    }
    return nullptr;
}

void EntryManager::UpdateTicketDetails(Ticket *ticket)
{
    // Implement the logic for updating ticket details
    // You can modify the necessary attributes of the ticket object based on specific requirements.
}

ParkingSlot *EntryManager::GetTheParkingSlot(std::string slotid)
{
    for (ParkingSlot *slot : GroundFloorParking.AllParkingVec)
    {
        if (slot->slotID == slotid)
        {
            return slot;
        }
    }
    return nullptr;
}

// ExitManager implementation

Ticket *ExitManager::GetTicketDetails(const std::string &id)
{
    for (Ticket *ticket : AllTicketsList)
    {
        if (ticket->getTicketID() == id)
        {
            ticket->SetStatus('P');
            return ticket;
        }
    }
    return nullptr;
}

void ExitManager::UpdateTicketDetails(Ticket *ticket)
{
    // Implement the logic for updating ticket details
    // You can modify the necessary attributes of the ticket object based on specific requirements.
}

void ExitManager::AllocateParking()
{
    // Implement the logic for freeing up parking slots and updating ticket details when vehicles exit the parking
}

void ExitManager::CreateTicket(ParkingSlot *parkSlot, const Vehicle &vehicle)
{
    if (parkSlot != nullptr)
    {
        parkSlot->releaseSlot();
        std::cout << "Ticket closed for slot " << parkSlot->slotID << std::endl;
    }
    else
    {
        std::cout << "Invalid parking slot." << std::endl;
    }
}

ParkingSlot *ExitManager::GetFreeParkingSlot(VehicleTypes type)
{
    // The ExitManager does not need to find free parking slots
    // Return nullptr as there are no slots to allocate
    return nullptr;
}

ParkingSlot *ExitManager::GetTheParkingSlot(std::string slotid)
{
    for (ParkingSlot *slot : GroundFloorParking.AllParkingVec)
    {
        if (slot->slotID == slotid)
        {
            return slot;
        }
    }
    return nullptr;
}
