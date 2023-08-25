#include "ParkingLot.hpp"

class ParkingDisplayDashboard
{
    const ParkingLot Lots;
    public:
    ParkingDisplayDashboard(const ParkingLot &Lots);
    ParkingDisplayDashboard();
    void DisplaySlots(bool type);
    bool GenerateParkingFullMessege();
};