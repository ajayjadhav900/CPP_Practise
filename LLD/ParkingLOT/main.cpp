#include "ParkingManager.hpp"

int main() {
    // Example usage of parking management system
    ParkingManager* entryMgr = new EntryManager();
    ParkingSlot* freeSlot = entryMgr->GetFreeParkingSlot(VehicleTypes::TWO_WHEELER);
    //Vehicle* vehicle = entryMgr->CreateVehicle(VehicleTypes::TWO_WHEELER);
    entryMgr->CreateTicket(freeSlot);

    ParkingManager* exitMgr = new ExitManager();
    Ticket* ticket = exitMgr->GetTicketDetails("TKT1");
    exitMgr->UpdateTicketDetails(ticket);

    return 0;
}
