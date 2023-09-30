#include "TheatreManagement.hpp"
#include <iostream>

TheatreManagement::TheatreManagement(const std::string& name, const std::string& city, int screens)
    : theatreName(name), city(city), noOfScreens(screens) {}

bool TheatreManagement::IsOpen() {
    // Implementation for checking if the theatre is open
    // ...
}

void TheatreManagement::DisplayMovies() {
    // Implementation for displaying the list of movies in the theatre
    // ...
}
