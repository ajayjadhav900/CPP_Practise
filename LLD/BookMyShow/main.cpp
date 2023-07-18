#include <iostream>
#include"BookingManager.hpp"
using namespace std;
int main()
{

    BookingManager Manager;
    Manager.GenerateDataForDays();

    Ticket tkt;
    tkt.BookingTheTicket("tkt1",1,"11",150,"DHOOM","B-12",TicketType::Platinum,Customer("Ajay"));
    bool book = Manager.GenerateBooking(tkt);
    cout<<"IS Ticket booked :" <<static_cast<int>(book);
    return 0;
}