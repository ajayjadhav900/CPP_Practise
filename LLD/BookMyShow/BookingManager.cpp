#include <string>
#include <iostream>
#include "BookingManager.hpp"

bool BookingManager::GenerateBooking(Ticket &tkt)
{
    AllTickets.push_back(tkt);
    return true;
}

void BookingManager::GenerateAllMovieList()
{
    AllMovieList.push_back(Movie("Dhoom3", "Hindi"));
    AllMovieList.push_back(Movie("Kytes", "Hindi"));
    AllMovieList.push_back(Movie("Sairat", "Marathi"));
    AllMovieList.push_back(Movie("IndianJones", "HindiDubbed"));
}

void BookingManager::GenerateAllScreenList()
{
    AllScreenList[0].ScreenID = 1;
    AllScreenList[0].ScreenMovies = AllMovieList;
    AllScreenList[0].NoOfSeats = 100;
    std::list<std::string> slots = {"9-12", "1-4", "5-8", "9-12"};
    AllScreenList[0].TimeSlotList = slots;
}

void BookingManager::GenerateDataForDays()
{

    std::cout << "---------------- Book My Show ----------------" << std::endl;
    std::cout << "Movie: Sairat: Dhoom" << std::endl;
    std::cout << "Cinema Hall: Abhiruchi Multiplex" << std::endl;
    std::cout << "Show Timings: " << std::endl;
    std::cout << "   - Day 1: Sairat 10:00 AM, Dhoom 2:00 PM, Kytes 6:00 PM" << std::endl;
    std::cout << "   - Day 2: Dhoom 11:00 AM, Sairat 3:00 PM, IndianJones 7:00 PM" << std::endl;
    std::cout << "   - Day 3: Dhoom 9:00 AM, IndianJones 1:00 PM, IndianJones 5:00 PM" << std::endl;
    std::cout << "   - Day 4: Dhoom 12:00 PM, IndianJones 4:00 PM, Sairat 8:00 PM" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}
