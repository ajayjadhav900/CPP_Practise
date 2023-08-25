#include "ParkingAttendant.hpp"
#include <vector>
class ParkingAdmin
{
public:
    int NoofEntryPoints{3};
    int NoofExitPoints{2};
    GroundFloor GroundFloorParking;
    ParkingDisplayDashboard Dashboard;
    vector<shared_ptr<ParkingAttendant>> ParkingAttendants;

    ParkingAdmin();
    void GenerateParking();
    void assignParkingLotToDashboard(GroundFloor &GroundFloorParking);

    shared_ptr<ParkingAttendant> GetEntryAttendant();
    shared_ptr<ParkingAttendant> GetExitAttendant();

};