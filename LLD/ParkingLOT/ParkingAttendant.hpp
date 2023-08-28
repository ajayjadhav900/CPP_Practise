#ifndef PARKINGMANAGER_HPP
#define PARKINGMANAGER_HPP

#include <vector>
#include <string>
#include <memory>
#include "Ticket.hpp"
#include "ParkingDisplayDashboard.hpp"

class GroundFloor;
class ParkingAttendant
{
public:
    GroundFloor &GroundFloorParking;
    std::vector<Ticket *> &AllTicketList;

    ParkingAttendant(GroundFloor &groundFloorParking,
                     std::vector<Ticket *> &allTicketList);

    ~ParkingAttendant();

    virtual std::shared_ptr<ParkingSlot> GetFreeParkingSlot(VehicleTypes type) = 0;
    virtual std::shared_ptr<ParkingSlot> GetTheParkingSlot(std::string slotid);
    virtual void CreateTicket(std::shared_ptr<ParkingSlot> parkSlot, const Vehicle &vehicle, int entryGateNo) = 0;
    virtual Ticket *GetTicketDetails(const std::string &id) = 0;
    virtual void UpdateTicketDetails(Ticket *ticket) = 0;
    virtual void AllocateParking() = 0;
    virtual void StartWorking(int GateNo) = 0;
};

class EntryManager : public ParkingAttendant
{
public:
    ParkingDisplayDashboard &Dashboard;
    std::vector<Ticket *> &AllTicketsList1;
    int GateNo;

    EntryManager(GroundFloor &groundFloorParking, ParkingDisplayDashboard &Dashboard,
                 std::vector<Ticket *> &allTicketList, int gateNo);
    virtual std::shared_ptr<ParkingSlot> GetFreeParkingSlot(VehicleTypes type) override;
    void CreateTicket(std::shared_ptr<ParkingSlot> parkSlot, 
    const Vehicle &vehicle,
    int entryGateNo) override;

    Ticket *GetTicketDetails(const std::string &id) override;
    void UpdateTicketDetails(Ticket *ticket) override;
    virtual std::shared_ptr<ParkingSlot> GetTheParkingSlot(std::string slotid) override;
    void AllocateParking() override;

    virtual void StartWorking(int GateNo);
};

class ExitManager : public ParkingAttendant
{
public:
    std::vector<Ticket *> &AllTicketsList1;
    int GateNo;

    ExitManager(GroundFloor &groundFloorParking, 
    std::vector<Ticket *> &allTicketList,
    int gateNo);
    Ticket *GetTicketDetails(const std::string &id) override;
    void UpdateTicketDetails(Ticket *ticket) override;
    void AllocateParking() override;
    void CreateTicket(std::shared_ptr<ParkingSlot> parkSlot, const Vehicle &vehicle, int entryGateNo) override;
    std::shared_ptr<ParkingSlot> GetFreeParkingSlot(VehicleTypes type) override;
    virtual std::shared_ptr<ParkingSlot> GetTheParkingSlot(std::string slotid) override;
    virtual void StartWorking(int gateNo);
    void printSeparator();
};

#endif
