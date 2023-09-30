#ifndef HALL_H
#define HALL_H

#include <string>

class Hall {
private:
    int hallId;
    std::string hallName;
    int movieId;

public:
    Hall(int id, const std::string& name, int movie);
    void DisplayDetails();
};

#endif  // HALL_H
