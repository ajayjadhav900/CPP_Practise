#include "Controller.hpp"
#include <iostream>
Controller::Controller()
{
    StartLift(5);
}

void Controller::StartLift(int no)
{
    FirstLift.CurrState = State::CLOSED;
    std::cout << "Lift started, State CLOSED" << std::endl;

    FirstLift.RunningState(no);
}

void Controller::RequestFromExternalUser(int no)
{
    RequestedList.push_back(no);
    ExtDisp.PressExternalButton(no);
    FirstLift.CurrState = State::OPENED;
    FirstLift.CurrDir = Direction::UP;
    FirstLift.ElevatorCarCurrentPosition();
    StartLift(no);
}