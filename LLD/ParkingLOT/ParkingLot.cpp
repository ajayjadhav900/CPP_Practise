#include <iostream>
#include <iomanip> // For setw

#include "ParkingLot.hpp"

void GroundFloor::GenerateParking()
{
    for (int i = 1; i <= NoOfBikesParking; ++i)
    {
        AllParkingVec.push_back(new BikeParkingSlot("B" + to_string(i), false, 0));
    }

    for (int i = 1; i <= NoOfCarParkings; ++i)
    {
        AllParkingVec.push_back(new CarParkingSlot("C" + to_string(i), false, 0));
    }

    for (int i = 1; i <= NoOfTrucksParking; ++i)
    {
        AllParkingVec.push_back(new TruckParkingSlot("T" + to_string(i), false, 0));
    }
}

// Print all parkings in tabular format
void GroundFloor::PrintParkingSlots()
{
    cout << " Parking Slots:" << endl;
    cout << setw(10) << "Slot ID" << setw(10) << "Occupied" << endl;
    for (auto bike : AllParkingVec)
    {
        if (bike->getVehicleType() == VehicleTypes::TWO_WHEELER)
            cout << setw(10) << bike->GetSlotID() << setw(10) << (bike->IsOccupied() ? "Yes" : "No") << setw(10) << endl;
    }

    cout << "\nCar Parking Slots:" << endl;
    cout << setw(10) << "Slot ID" << setw(10) << "Occupied" << setw(10) << endl;
    for (auto &car : AllParkingVec)
    {
        if (car->getVehicleType() == VehicleTypes::FOUR_WHEELER)
            cout << setw(10) << car->GetSlotID() << setw(10) << (car->IsOccupied() ? "Yes" : "No") << endl;
    }

    cout << "\nTruck Parking Slots:" << endl;
    cout << setw(10) << "Slot ID" << setw(10) << "Occupied" << setw(10) << endl;
    for (auto &truck : AllParkingVec)
    {
        if (truck->getVehicleType() == VehicleTypes::TRUCK)
            cout << setw(10) << truck->GetSlotID() << setw(10) << (truck->IsOccupied() ? "Yes" : "No") << endl;
    }
}