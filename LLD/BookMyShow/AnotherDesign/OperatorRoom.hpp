#ifndef OPERATORROOM_H
#define OPERATORROOM_H

#include <string>

class OperatorRoom {
private:
    int inchargeId;
    std::string inchargeName;
    int hallId;

public:
    OperatorRoom(int id, const std::string& name, int hall);
    void Control();
};

#endif  // OPERATORROOM_H
