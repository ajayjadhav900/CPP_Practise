#ifndef PARKINGMANAGER_HPP
#define PARKINGMANAGER_HPP

#include <vector>
#include <string>
#include "ParkingSlot.hpp"
#include "Ticket.hpp"
#include"ParkingLot.hpp"
class ParkingManager
{
public:
    std::vector<Ticket *> AllTicketsList;
    GroundFloor GroundFloorParking;

    virtual void AllocateParking() = 0;
    void GenerateParking();
    ParkingManager();
    virtual ParkingSlot *GetFreeParkingSlot(VehicleTypes type) = 0;
    virtual ParkingSlot *GetTheParkingSlot(std::string slotid);
    virtual void CreateTicket(ParkingSlot *parkSlot, const Vehicle &vehicle) = 0;
    virtual Ticket *GetTicketDetails(const std::string &id) = 0;
    virtual void UpdateTicketDetails(Ticket *ticket) = 0;
};

class EntryManager : public ParkingManager
{
public:
    ParkingSlot *GetFreeParkingSlot(VehicleTypes type) override;
    void CreateTicket(ParkingSlot *parkSlot, const Vehicle &vehicle) override;
    void AllocateParking() override;
    Ticket *GetTicketDetails(const std::string &id) override;
    void UpdateTicketDetails(Ticket *ticket) override;
    virtual ParkingSlot *GetTheParkingSlot(std::string slotid) override;
};

class ExitManager : public ParkingManager
{
public:
    Ticket *GetTicketDetails(const std::string &id) override;
    void UpdateTicketDetails(Ticket *ticket) override;
    void AllocateParking() override;
    void CreateTicket(ParkingSlot *parkSlot, const Vehicle &vehicle) override;
    ParkingSlot *GetFreeParkingSlot(VehicleTypes type) override;
    virtual ParkingSlot *GetTheParkingSlot(std::string slotid) override;
};

#endif
