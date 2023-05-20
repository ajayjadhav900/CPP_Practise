#include <iostream>
#include "PlayGame.hpp"
using namespace std;
int main()
{
    PlayGame play;
    play.initializeGame();
    if (play.StartGame())
    {
        cout << "There is a winner";
    }
    else
    {
        cout << "There is a no winner, Game draw!!!";
    }

    return 0;
}