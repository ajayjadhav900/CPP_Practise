cmake_minimum_required(VERSION 3.12)

project(ParkingManagement)

# Add executable
add_executable(parking_management
    ParkingSlot.cpp
    ParkingLot.cpp
    Vehicle.cpp
    Payment.cpp
    Ticket.cpp
    ParkingAdmin.cpp
    ParkingAttendant.cpp
    main.cpp
)

# Set C++ standard
set_target_properties(parking_management PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

# Optional: Add additional include directories if needed
# target_include_directories(parking_management PRIVATE
#     include
# )

# Optional: Add additional link directories if needed
# target_link_directories(parking_management PRIVATE
#     ${CMAKE_SOURCE_DIR}/lib
# )

# Optional: Link libraries if needed
# target_link_libraries(parking_management PRIVATE
#     library_name
# )
