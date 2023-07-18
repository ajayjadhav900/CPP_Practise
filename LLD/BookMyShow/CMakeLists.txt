cmake_minimum_required(VERSION 3.10)
project(BookMyShow)

set(CMAKE_CXX_STANDARD 11)

# Add the source files for the project
set(SOURCES
    Customer.cpp
    Movie.cpp
    Screen.cpp
    Ticket.cpp
    BookingManager.cpp
    main.cpp
)

# Create the executable
add_executable(bookmyshow ${SOURCES})
