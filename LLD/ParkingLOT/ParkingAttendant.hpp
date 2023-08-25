#ifndef PARKINGMANAGER_HPP
#define PARKINGMANAGER_HPP

#include <vector>
#include <string>
#include <memory>
#include "Ticket.hpp"
class ParkingDisplayDashboard;
class GroundFloor;
class ParkingAttendant
{
public:
    std::vector<Ticket *> AllTicketsList;
    GroundFloor &GroundFloorParking;
    ParkingAttendant(GroundFloor &groundFloorParking);
    ~ParkingAttendant();

    virtual std::shared_ptr<ParkingSlot> GetFreeParkingSlot(VehicleTypes type) = 0;
    virtual std::shared_ptr<ParkingSlot> GetTheParkingSlot(std::string slotid);
    virtual void CreateTicket(std::shared_ptr<ParkingSlot> parkSlot, const Vehicle &vehicle) = 0;
    virtual Ticket *GetTicketDetails(const std::string &id) = 0;
    virtual void UpdateTicketDetails(Ticket *ticket) = 0;
    virtual void AllocateParking() = 0;
};

class EntryManager : public ParkingAttendant
{
public:
    ParkingDisplayDashboard &Dashboard;
    EntryManager(GroundFloor &groundFloorParking, ParkingDisplayDashboard &Dashboard);
    virtual std::shared_ptr<ParkingSlot> GetFreeParkingSlot(VehicleTypes type) override;
    void CreateTicket(std::shared_ptr<ParkingSlot> parkSlot, const Vehicle &vehicle) override;

    Ticket *GetTicketDetails(const std::string &id) override;
    void UpdateTicketDetails(Ticket *ticket) override;
    virtual std::shared_ptr<ParkingSlot> GetTheParkingSlot(std::string slotid) override;
    void AllocateParking() override;

    void StartWorking();
};

class ExitManager : public ParkingAttendant
{
public:
    ExitManager(GroundFloor &groundFloorParking);
    Ticket *GetTicketDetails(const std::string &id) override;
    void UpdateTicketDetails(Ticket *ticket) override;
    void AllocateParking() override;
    void CreateTicket(std::shared_ptr<ParkingSlot> parkSlot, const Vehicle &vehicle) override;
    std::shared_ptr<ParkingSlot> GetFreeParkingSlot(VehicleTypes type) override;
    virtual std::shared_ptr<ParkingSlot> GetTheParkingSlot(std::string slotid) override;
    void StartWorking();
    void printSeparator();
};

#endif
