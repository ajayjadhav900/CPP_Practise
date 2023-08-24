#include "ParkingSlot.hpp"
#include <list>
using namespace std;
class ParkingLot
{
public:
    ParkingLot()
    {
    }
    ~ParkingLot();
    int MaxCapacity{10};
    int NoOfCarParkings{4};
    int NoOfBikesParking{4};
    int NoOfTrucksParking{2};
    int FloorNo{0};
    int currentParkSlots{0};
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