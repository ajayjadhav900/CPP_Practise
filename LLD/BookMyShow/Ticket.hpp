#include <string>
#include "Customer.hpp"
using namespace std;
enum class TicketType
{
    Platinum,
    Gold,
    Silver,
    Balcony
};
class Ticket
{

    std::string ID;
    int ScreenNo;
    std::string TimeSlot;
    int Amount;
    std::string MovieName;
    std::string SeatNo;
    TicketType TktType;
    Customer TktCustomer;

public:
    bool BookingTheTicket(string id,
                                  int no,
                                  string slot,
                                  int amt,
                                  string moviename,
                                  string seatno,
                                  TicketType type,
                                  Customer Cust);
};