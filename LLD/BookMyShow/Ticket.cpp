#include "Ticket.hpp"

using namespace std;
bool Ticket::BookingTheTicket(string id,
                              int no,
                              string slot,
                              int amt,
                              string moviename,
                              string seatno,
                              TicketType type,
                              Customer Cust)
{
    ID = id;
    ScreenNo = no;
    TimeSlot = slot;
    Amount = amt;
    MovieName = moviename;
    SeatNo = seatno;
    TktType = type;
    TktCustomer = Cust;
    return true;
}
