#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>

// Forward declaration
class DiagnosticHandler;

// Represents a diagnostic message
struct DiagnosticMessage {
    uint16_t code;
    std::string description;
    bool handled;
    std::string handlerName; // For debugging purposes

    DiagnosticMessage(uint16_t c, const std::string& desc) : code(c), description(desc), handled(false), handlerName("") {}
};

// Base handler class
class DiagnosticHandler {
public:
    virtual ~DiagnosticHandler() = default;
    virtual void handleMessage(DiagnosticMessage& message) = 0;
    void setNextHandler(std::unique_ptr<DiagnosticHandler> next) {
        nextHandler = std::move(next);
    }

protected:
    std::unique_ptr<DiagnosticHandler> nextHandler;

    void passToNext(DiagnosticMessage& message) {
        if (nextHandler) {
            nextHandler->handleMessage(message);
        }
    }
};

// Concrete handler for a specific DTC (Diagnostic Trouble Code) range or type
class DTCRangeHandler : public DiagnosticHandler {
private:
    uint16_t minCode;
    uint16_t maxCode;
    std::string handlerName;

public:
    DTCRangeHandler(uint16_t min, uint16_t max, const std::string& name) : minCode(min), maxCode(max), handlerName(name) {}

    void handleMessage(DiagnosticMessage& message) override {
        if (message.code >= minCode && message.code <= maxCode && !message.handled) {
            // Handle the message
            message.handled = true;
            message.handlerName = handlerName;
            std::cout << "DTCRangeHandler (" << handlerName << ") handled message: " << message.description << " (Code: " << message.code << ")" << std::endl;
            // Perform specific actions for this DTC range, e.g.,
            // - Retrieve detailed information from a database
            // - Trigger a specific diagnostic routine
            // - Log the error with specific parameters
        } else {
            // Pass the message to the next handler
            passToNext(message);
        }
    }
};

// Concrete handler for a specific fault type
class FaultTypeHandler : public DiagnosticHandler {
private:
    std::string faultType;
    std::string handlerName;

public:
    FaultTypeHandler(const std::string& type, const std::string& name) : faultType(type), handlerName(name) {}

    void handleMessage(DiagnosticMessage& message) override {
        // In a real system, you might have a way to get the fault type from the message.
        // For this example, we'll just check if the description contains the fault type.
        if (message.description.find(faultType) != std::string::npos && !message.handled) {
            message.handled = true;
            message.handlerName = handlerName;
            std::cout << "FaultTypeHandler (" << handlerName << ") handled message: " << message.description << " (Code: " << message.code << ")" << std::endl;
            // Handle the message, e.g.,
            // -  Send a notification to the driver
            // -  Store the fault in non-volatile memory
            // -  Disable a specific system
        } else {
            passToNext(message);
        }
    }
};

// Concrete handler to handle default or unknown messages
class DefaultHandler : public DiagnosticHandler {
public:
    DefaultHandler(const std::string& name) : handlerName(name){}
    void handleMessage(DiagnosticMessage& message) override {
        if (!message.handled) {
            message.handled = true;
            message.handlerName = handlerName;
            std::cout << "DefaultHandler (" << handlerName << ") handled message: " << message.description << " (Code: " << message.code << ")" << std::endl;
            // Handle the message as a default case, e.g.,
            // - Log the error to a generic log file
            // - Send a generic error response
        }
    }
private:
    std::string handlerName;
};

int main() {
    // Create diagnostic messages
    std::vector<DiagnosticMessage> messages = {
        {0x0101, "Engine Overheat"},
        {0x0102, "High Coolant Temperature"},
        {0x0210, "Transmission Fault"},
        {0x0300, "Brake System Malfunction"},
        {0x0500, "Unknown Error Code"},
        {0x0110, "Engine Oil Pressure Low"}
    };

    // Build the chain of responsibility.  Use smart pointers to manage memory.
    std::unique_ptr<DiagnosticHandler> handlerChain =
        std::make_unique<DTCRangeHandler>(0x0100, 0x01FF, "EngineRelatedHandler"); // Handles 0x01xx
    handlerChain->setNextHandler(std::make_unique<DTCRangeHandler>(0x0200, 0x02FF, "TransmissionHandler")); // Handles 0x02xx
    handlerChain->setNextHandler(std::make_unique<FaultTypeHandler>("Fault", "GenericFaultHandler")); // Handles messages containing "Fault"
    handlerChain->setNextHandler(std::make_unique<DefaultHandler>("DefaultHandler")); // Handles everything else.

    // Process the messages
    for (auto& message : messages) {
        handlerChain->handleMessage(message);
    }

     std::cout << "\nMessage Handling Summary:\n";
    for (const auto& message : messages) {
        std::cout << "Code: " << message.code
                  << ", Description: " << message.description
                  << ", Handled: " << (message.handled ? "Yes" : "No")
                  << ", Handler: " << message.handlerName
                  << std::endl;
    }

    return 0;
}
