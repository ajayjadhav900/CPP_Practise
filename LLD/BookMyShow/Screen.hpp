#include <vector>
#include <list>
#include<string>
#include "Movie.hpp"
class Screen
{
    public:
    int ScreenID;
    std::list<Movie > ScreenMovies;
    std::list<std::string> TimeSlotList;
    int NoOfSeats;

    public:
    Screen();

};

