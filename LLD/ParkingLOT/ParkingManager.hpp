#include <vector>
#include "ParkingSlot.hpp"
#include "Ticket.hpp"
class ParkingManager
{
public:
    std::vector<ParkingSlot> AllParkingVec;
    std::vector<Ticket *> AllTicketsList;
    void virtual AllocateParking() = 0;
    void virtual GenerateParking() = 0;
    virtual ParkingSlot *GetFreeParkingSlot(VehicleTypes type) = 0;
    virtual    void CreateTicket(ParkingSlot *parkSlot) = 0;
     virtual   Ticket *GetTicketDetails(std::string id) = 0;


};
class EntryManager : public ParkingManager
{
public:
EntryManager();
    ParkingSlot *GetFreeParkingSlot(VehicleTypes type);
   // Vehicle *CreateVehicle(VehicleTypes type);
    void CreateTicket(ParkingSlot *parkSlot);
    void GenerateParking();
    void AllocateParking();
    Ticket *GetTicketDetails(std::string id);

};

class ExitManager : public ParkingManager
{
public:
    Ticket *GetTicketDetails(std::string id);
    void UpdateTicketDetails(Ticket *);
    void GenerateParking();
        void AllocateParking();
            ParkingSlot *GetFreeParkingSlot(VehicleTypes type);
                void CreateTicket(ParkingSlot *parkSlot);



};
