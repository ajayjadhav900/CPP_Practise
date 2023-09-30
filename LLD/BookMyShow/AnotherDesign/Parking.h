#ifndef PARKING_H
#define PARKING_H

class Parking {
private:
    int totalSlots;
    int slotsOccupied;

public:
    Parking(int totalSlots, int slotsOccupied);
    void Park();
    void Pay();
};

#endif  // PARKING_H
