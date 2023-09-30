#ifndef RESTROOM_H
#define RESTROOM_H

class RestRoom {
private:
    int noOfSlots;

public:
    RestRoom(int slots);
    void Use();
};

#endif  // RESTROOM_H
