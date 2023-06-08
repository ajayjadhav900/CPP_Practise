# Compiler
CC := g++

# Compiler flags
CFLAGS := -std=c++11 -Wall

# Source files
SRCS := ParkingSlot.cpp ParkingManager.cpp Ticket.cpp main.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Executable name
TARGET := parking_management

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
