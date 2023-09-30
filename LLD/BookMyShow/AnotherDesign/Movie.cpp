#include "Movie.hpp"
#include <iostream>

Movie::Movie(int id, const std::string& name, const std::string& genre, int duration, int hall, const std::string& timings)
    : movieId(id), movieName(name), genre(genre), duration(duration), hallNumber(hall), timings(timings) {}

void Movie::DisplayMovieDetails() {
    // Implementation for displaying the movie details
    // ...
}
