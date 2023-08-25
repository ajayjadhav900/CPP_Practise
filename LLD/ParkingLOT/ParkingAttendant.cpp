#include "ParkingAttendant.hpp"
#include "ParkingLot.hpp"
#include "ParkingDisplayDashboard.hpp"
#include <iostream>
#include <iomanip>

using namespace std;
// ParkingAttendant implementation

ParkingAttendant::ParkingAttendant(GroundFloor &groundFloorParking) : GroundFloorParking(groundFloorParking)
{
}

ParkingAttendant::~ParkingAttendant()
{
    AllTicketsList.clear();
}

std::shared_ptr< ParkingSlot >ParkingAttendant::GetTheParkingSlot(std::string slotid)
{
    for (std::shared_ptr< ParkingSlot >slot : GroundFloorParking.AllParkingVec)
    {
        if (slot->slotID == slotid)
        {
            return slot;
        }
    }
    return nullptr;
}

// EntryManager implementation

EntryManager::EntryManager(GroundFloor &groundFloorParking, ParkingDisplayDashboard &dashboard)
    : ParkingAttendant(groundFloorParking), Dashboard(dashboard)
{
}

std::shared_ptr< ParkingSlot >EntryManager::GetFreeParkingSlot(VehicleTypes type)
{
    for (std::shared_ptr< ParkingSlot >slot : GroundFloorParking.AllParkingVec)
    {
        if (!slot->isOccupied && slot->getVehicleType() == type)
        {
            GroundFloorParking.currentParkSlots++;
            return slot;
        }
    }
    return nullptr;
}

void EntryManager::CreateTicket(std::shared_ptr< ParkingSlot >parkSlot, const Vehicle &vehicle)
{
    if (parkSlot != nullptr)
    {
        Ticket *ticket = new Ticket(parkSlot->slotID, vehicle);
        AllTicketsList.push_back(ticket);
        parkSlot->parkVehicle();
        std::cout << "Ticket created for slot " << parkSlot->slotID << std::endl;
        std::cout << "Ticket ID created : " << ticket->getTicketID() << std::endl;

        delete ticket;
    }
    else
    {
        std::cout << "No free parking slot available for the given vehicle type." << std::endl;
    }
}

void EntryManager::AllocateParking()
{
    std::cout << "\nParking allocated!!!\n";
}

void EntryManager::StartWorking()
{
    while (1)
    {
        int ch;
        cout << "\n\n--------------Entry MANAGER----------\n\n";
        cout << "\t1: Dashboard ALL slots \t 2: Park Vehicle\t 3: Parked Slots\t 4:Exit \nEnter Choice: ";
        cin >> ch;
        if (ch == 2)
        {

            cout << "\n\nNew Vehicle Arrived...\n";
            if (Dashboard.GenerateParkingFullMessege())
            {
                cout << "Parking FULL!!!\n";
                return;
            }
            int ch;
            cout << "\n\nEnter the vehicle type\n 1: Bike 2: Car 3: Truck\n";
            cin >> ch;
            if (ch == 1)
            {
                std::shared_ptr< ParkingSlot >bikeSlot = GetFreeParkingSlot(VehicleTypes::TWO_WHEELER);
                // Create a ticket for the bike
                Car bk("MH14 GF1243", VehicleTypes::TWO_WHEELER);
                Vehicle &veh = bk;
                CreateTicket(bikeSlot, veh);
            }
            else if (ch == 2)
            {
                std::shared_ptr< ParkingSlot >bikeSlot = GetFreeParkingSlot(VehicleTypes::FOUR_WHEELER);
                // Create a ticket for the bike
                Car bk("MH14 GN8617", VehicleTypes::FOUR_WHEELER);
                Vehicle &veh = bk;
                CreateTicket(bikeSlot, veh);
            }

            AllocateParking();
        }
        else if (ch == 3)
        {
            Dashboard.DisplaySlots(true);
        }
        else if (ch == 1)
        {
            GroundFloorParking.PrintParkingSlots();
        }
        else if (ch == 4)
        {
            break;
        }
        else
        {
            cout << "\n\nEnter the valid choice!!!\n\n";
            cin >> ch;
        }
    }
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

std::shared_ptr< ParkingSlot >EntryManager::GetTheParkingSlot(std::string slotid)
{
    for (std::shared_ptr< ParkingSlot >slot : GroundFloorParking.AllParkingVec)
    {
        if (slot->slotID == slotid)
        {
            return slot;
        }
    }
    return nullptr;
}

// ExitManager implementation

ExitManager::ExitManager(GroundFloor &groundFloorParking) : ParkingAttendant(groundFloorParking)
{
}

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

void ExitManager::CreateTicket(std::shared_ptr< ParkingSlot >parkSlot, const Vehicle &vehicle)
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

std::shared_ptr< ParkingSlot >ExitManager::GetFreeParkingSlot(VehicleTypes type)
{
    // The ExitManager does not need to find free parking slots
    // Return nullptr as there are no slots to allocate
    return nullptr;
}

std::shared_ptr< ParkingSlot >ExitManager::GetTheParkingSlot(std::string slotid)
{
    for (std::shared_ptr< ParkingSlot >slot : GroundFloorParking.AllParkingVec)
    {
        if (slot->slotID == slotid)
        {
            return slot;
        }
    }
    return nullptr;
}

void ExitManager::StartWorking()
{
    while (1)
    {
        std::string tktID;
        int ch;
        cout << "\n\n--------------EXIT MANAGER----------\n\n";
        cout << "\t1: Payment\t 2: Exit \nEnter Choice: ";
        cin >> ch;
        if (ch == 1)
        {
            cout << "Enter the ticket ID for payment: ";
            cin >> tktID;
            Ticket *exitTicket = GetTicketDetails(tktID);
            if (exitTicket == nullptr)
            {
                cout << "Please enter Valid ticket!!!";
                continue;
            }
            std::cout << "Ticket Status: (ACTIVE: 0 PAID: 1) " << static_cast<int>(exitTicket->GetStatus()) << std::endl;
            if (exitTicket != nullptr)
            {
                // Perform operations with the ticket
                // For example, set the exit time and update the ticket details
                exitTicket->setExitTime();
                UpdateTicketDetails(exitTicket);
            }

            if (exitTicket != nullptr)
            {
                // Perform operations with the ticket at the exit
                // For example, calculate the parking duration and print the details
                std::chrono::steady_clock::duration duration = exitTicket->getExitTime() - exitTicket->getEntryTime();
                long long parkingDuration = std::chrono::duration_cast<std::chrono::minutes>(duration).count();

                std::cout << "\n\n------ Parking Ticket ------" << std::endl;
                std::cout << "Ticket ID: " << exitTicket->getTicketID() << std::endl;
                std::cout << "Ticket Status: " << static_cast<int>(exitTicket->GetStatus()) << std::endl;
                std::cout << "Slot ID: " << exitTicket->getSlotID() << std::endl;
                std::cout << "Vehile Reg no: " << exitTicket->GetVehicleData().RegNo.c_str();
                VehicleTypes type = exitTicket->GetVehicleData().Type;
                std::cout << " Vehicle Type: " << static_cast<int>(type) << std::endl;
                std::cout << "Parking duration: " << parkingDuration << " minutes" << std::endl;
                std::cout << "Cost of ticket: " << exitTicket->EstimateCost() << " rupees" << std::endl;
                std::cout << "Payment: " << std::endl;
                exitTicket->DoThePayment(PaymentMode::ONLINEAPP, exitTicket->EstimateCost());

                // Ticket footer
                printSeparator();
                std::cout << "Thank you for using our parking services!" << std::endl;

                auto slot = GetTheParkingSlot(exitTicket->getSlotID());
                if (slot != nullptr)
                    slot->releaseSlot();
                else
                    cout << "\n\nIssue in releasing parking slot, Please connect with Administrator!!!\n\n";

                cout << "\nCurrent Park slots are " << --GroundFloorParking.currentParkSlots << endl;
            }
        }
        else if (ch == 2)
        {
            break;
        }
        else
        {
            cout << "\n\nEnter the valid choice!!!\n\n";
            cin >> ch;
        }
    }
}

void ExitManager::printSeparator()
{
    std::cout << std::setfill('-') << std::setw(50) << "-" << std::setfill(' ') << std::endl;
}
