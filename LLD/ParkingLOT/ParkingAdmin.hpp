#include "ParkingAttendant.hpp"
#include <vector>
#include <map>
class ParkingAdmin
{
public:
    int NoofEntryPoints{3};
    int NoofExitPoints{2};
    GroundFloor GroundFloorParking;
    ParkingDisplayDashboard Dashboard;
    std::map<int ,shared_ptr<ParkingAttendant>> ParkingAttendants;
    std::vector<Ticket *> AllTicketsList;

    ParkingAdmin();
    ~ParkingAdmin();
    void GenerateParking();
    void assignParkingLotToDashboard(GroundFloor &GroundFloorParking);

    shared_ptr<ParkingAttendant> GetEntryAttendant();
    shared_ptr<ParkingAttendant> GetExitAttendant();
};