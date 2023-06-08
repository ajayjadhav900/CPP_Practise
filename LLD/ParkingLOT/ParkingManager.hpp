#ifndef PARKINGMANAGER_HPP
#define PARKINGMANAGER_HPP

#include <vector>
#include <string>
#include "ParkingSlot.hpp"
#include "Ticket.hpp"

class ParkingManager {
public:
    std::vector<ParkingSlot*> AllParkingVec;
    std::vector<Ticket*> AllTicketsList;

    virtual void AllocateParking() = 0;
    void GenerateParking();
    ParkingManager();
    virtual ParkingSlot* GetFreeParkingSlot(VehicleTypes type) = 0;
    virtual void CreateTicket(ParkingSlot* parkSlot) = 0;
    virtual Ticket* GetTicketDetails(const std::string& id) = 0;
    virtual void UpdateTicketDetails(Ticket* ticket) = 0;
};

class EntryManager : public ParkingManager {
public:
    ParkingSlot* GetFreeParkingSlot(VehicleTypes type) override;
    void CreateTicket(ParkingSlot* parkSlot) override;
    void AllocateParking() override;
    Ticket* GetTicketDetails(const std::string& id) override;
    void UpdateTicketDetails(Ticket* ticket) override;
};

class ExitManager : public ParkingManager {
public:
    Ticket* GetTicketDetails(const std::string& id) override;
    void UpdateTicketDetails(Ticket* ticket) override;
    void AllocateParking() override;
    void CreateTicket(ParkingSlot* parkSlot) override;
    ParkingSlot* GetFreeParkingSlot(VehicleTypes type) override;
};

#endif
