
class ParkingLot;
class ParkingDisplayDashboard
{
    const ParkingLot &Lots;
    public:
    ParkingDisplayDashboard(const ParkingLot &Lots);
    void DisplaySlots(bool type);
    bool GenerateParkingFullMessege();
};