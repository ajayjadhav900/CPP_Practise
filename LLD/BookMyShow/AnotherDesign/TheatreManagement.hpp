#ifndef THEATREMANAGEMENT_H
#define THEATREMANAGEMENT_H

#include <string>
#include <vector>
#include "OperatorRoom.hpp"
#include "Hall.h"
#include "Movie.hpp"
#include "Ticket.hpp"
#include "Parking.h"

class TheatreManagement {
private:
    std::string theatreName;
    std::string city;
    int noOfScreens;
    std::vector<OperatorRoom> operatorRooms;
    std::vector<Hall> halls;
    std::vector<Movie> movies;
    std::vector<Ticket> tickets;
    Parking* parking;//Aggregation

public:
    TheatreManagement(const std::string& name, const std::string& city, int screens, Parking* parking);
    bool IsOpen();
    void DisplayMovies();
    // Additional methods for managing OperatorRooms, Halls, Movies, and Tickets
    void AddOperatorRoom(const OperatorRoom& room);
    void AddHall(const Hall& hall);
    void AddMovie(const Movie& movie);
    void AddTicket(const Ticket& ticket);
    // Method for managing Parking
    void SetParking(Parking* parking);
    Parking* GetParking();
};

#endif  // THEATREMANAGEMENT_H
