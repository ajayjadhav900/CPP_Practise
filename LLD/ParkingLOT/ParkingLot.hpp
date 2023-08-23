#include "ParkingSlot.hpp"
#include <list>
using namespace std;
class ParkingLot
{
public:
    ParkingLot()
    {
    }
    int MaxCapacity{100};
    int NoOfCarParkings{40};
    int NoOfBikesParking{40};
    int NoOfTrucksParking{20};
    int FloorNo{0};
    list<ParkingSlot *> AllParkingVec;

    ParkingLot(int maxCapacity,
               int noOfCarParkings,
               int noOfBikesParking,
               int noOfTrucksParking,
               int floorNo) : MaxCapacity(maxCapacity),
                              NoOfCarParkings(noOfCarParkings),
                              NoOfBikesParking(noOfBikesParking),
                              NoOfTrucksParking(noOfTrucksParking),
                              FloorNo(floorNo)
    {
    }
};

class GroundFloor : public ParkingLot
{
public:
    GroundFloor()
    {
    }
    GroundFloor(int maxCapacity,
                int noOfCarParkings,
                int noOfBikesParking,
                int noOfTrucksParking,
                int floorNo) : ParkingLot(maxCapacity,
                                          noOfCarParkings,
                                          noOfBikesParking,
                                          noOfTrucksParking,
                                          floorNo)
    {
    }

    // Generate Lists Bikes = 50 , Cars = 40  and Trucks  = 10 list
    void GenerateParking();
    void PrintParkingSlots();
};