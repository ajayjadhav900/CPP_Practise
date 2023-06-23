#include "DisplayPanel.hpp"
#include "InternalDispatcher.hpp"
#include <vector>
enum class State
{
    IDLE,
    RUNNING,
    OPENED,
    CLOSED
};

enum class Direction
{
    UP,
    DOWN
};
class ElevatorCar
{
public:
    int CurrentFloorNo;
    State CurrState;
    DisplayPanel Panel;
    InternalDispatcher IntDisp;
    Direction CurrDir;
    ElevatorCar();
    void ElevatorCarCurrentPosition();
    void SetCurrentState(int, Direction dir, State state);
    void PressInternalButton(int);
    void RunningState(int);

};
