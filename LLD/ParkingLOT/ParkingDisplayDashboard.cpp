#include "ParkingDisplayDashboard.hpp"
#include "Vehicle.hpp"
#include <iostream>
#include <iomanip> // For setw
#include "ParkingLot.hpp"
using namespace std;
ParkingDisplayDashboard::ParkingDisplayDashboard(const ParkingLot &lots) : Lots(lots)
{
}

void ParkingDisplayDashboard::DisplaySlots(bool type)
{
    cout << " Parking Slots:" << endl;
    cout << setw(10) << "Slot ID" << setw(10) << "Occupied" << endl;
    cout << "\nBike Parking Slots:" << endl;

    for (auto bike : Lots.AllParkingVec)
    {
        if (bike->getVehicleType() == VehicleTypes::TWO_WHEELER &&
            bike->isOccupied == type)
            cout << setw(10) << bike->GetSlotID() << setw(10) << (bike->IsOccupied() ? "Yes" : "No") << setw(10) << endl;
    }

    cout << "\nCar Parking Slots:" << endl;
    cout << setw(10) << "Slot ID" << setw(10) << "Occupied" << setw(10) << endl;
    for (auto &car : Lots.AllParkingVec)
    {
        if (car->getVehicleType() == VehicleTypes::FOUR_WHEELER &&
            car->isOccupied == type)
            cout << setw(10) << car->GetSlotID() << setw(10) << (car->IsOccupied() ? "Yes" : "No") << endl;
    }

    cout << "\nTruck Parking Slots:" << endl;
    cout << setw(10) << "Slot ID" << setw(10) << "Occupied" << setw(10) << endl;
    for (auto &truck : Lots.AllParkingVec)
    {
        if (truck->getVehicleType() == VehicleTypes::TRUCK &&
            truck->isOccupied == type)
            cout << setw(10) << truck->GetSlotID() << setw(10) << (truck->IsOccupied() ? "Yes" : "No") << endl;
    }
}

bool ParkingDisplayDashboard::GenerateParkingFullMessege()
{
    if (Lots.currentParkSlots == Lots.MaxCapacity)
    {
        cout << "\nParking floor is Full!!!\n";
        return true;
    }
    return false;
}
