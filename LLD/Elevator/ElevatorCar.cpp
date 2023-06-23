#include "ElevatorCar.hpp"
#include <iostream>
ElevatorCar::ElevatorCar()
{
    CurrentFloorNo = 5;
    CurrState = State::IDLE;
}

void ElevatorCar::ElevatorCarCurrentPosition()
{
 std::cout << "Elevator is currently at " << CurrentFloorNo << " with direction (U, D)"<< static_cast<int>(CurrDir) << " with lift state (I,R,O,C)  " << static_cast<int>(CurrState) << std::endl;

}

void ElevatorCar::SetCurrentState(int no, Direction dir, State state)
{
    CurrentFloorNo = no;
    CurrState = state;
    CurrDir = dir;
    ElevatorCarCurrentPosition();
}

void ElevatorCar::PressInternalButton(int no)
{
    this->IntDisp.PressInternalButton(no);
    this->SetCurrentState(no,Direction::UP,State::CLOSED);
    RunningState(no);
}

void ElevatorCar::RunningState(int reqNo)
{
    std::cout<<"In running state RUNNING"<<std::endl;
    if (CurrentFloorNo < reqNo)
    {
        CurrDir = Direction::UP;
    }
    else
    {
        CurrDir = Direction::DOWN;
    }
    CurrState = State::RUNNING;
}
