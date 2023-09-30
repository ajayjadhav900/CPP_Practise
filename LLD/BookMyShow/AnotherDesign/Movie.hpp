#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
private:
    int movieId;
    std::string movieName;
    std::string genre;
    int duration;
    int hallNumber;
    std::string timings;

public:
    Movie(int id, const std::string& name, const std::string& genre, int duration, int hall, const std::string& timings);
    void DisplayMovieDetails();
};

#endif  // MOVIE_H
