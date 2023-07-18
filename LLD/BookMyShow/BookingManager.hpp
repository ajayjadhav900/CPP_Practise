
#include "Ticket.hpp"
#include "Screen.hpp"

class BookingManager
{
    std::vector<Ticket> AllTickets;
    std::list<Movie> AllMovieList; 
    std::vector<Screen> AllScreenList;
    public:
    bool GenerateBooking(Ticket &tkt);
    void GenerateAllMovieList();
    void GenerateAllScreenList();
    void GenerateDataForDays();
};