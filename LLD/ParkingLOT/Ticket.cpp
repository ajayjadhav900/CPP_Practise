#include "Ticket.hpp"

Ticket::Ticket(const std::string& slotID)
    : slotID(slotID), entryTime(std::chrono::steady_clock::now()) {
    // Generate a unique ticket ID based on some logic
    // For simplicity, let's assume it's based on the current time
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(entryTime.time_since_epoch());
    ticketID = std::to_string(ms.count());
}

std::string Ticket::getTicketID() const {
    return ticketID;
}

std::string Ticket::getSlotID() const {
    return slotID;
}

std::chrono::steady_clock::time_point Ticket::getEntryTime() const {
    return entryTime;
}

std::chrono::steady_clock::time_point Ticket::getExitTime() const {
    return exitTime;
}

void Ticket::setExitTime() {
    exitTime = std::chrono::steady_clock::now();
}
