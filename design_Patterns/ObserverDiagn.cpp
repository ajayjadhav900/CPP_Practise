#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

// Observer Interface
class DiagnosticObserver
{
public:
    virtual void update(const std::string &diagnosticCode) = 0;
    virtual ~DiagnosticObserver() = default;
};

// Concrete Observers
class DiagnosticDisplay : public DiagnosticObserver
{
public:
    void update(const std::string &diagnosticCode) override
    {
        std::cout << "Diagnostic Display: Received code - " << diagnosticCode << std::endl;
    }
};

class DiagnosticLogger : public DiagnosticObserver
{
public:
    void update(const std::string &diagnosticCode) override
    {
        std::cout << "Diagnostic Logger: Logging code - " << diagnosticCode << std::endl;
        // Simulate logging to a file or database
    }
};

class DiagnosticAlert : public DiagnosticObserver
{
public:
    void update(const std::string &diagnosticCode) override
    {
        std::cout << "Diagnostic Alert: Triggering alert for code - " << diagnosticCode << std::endl;
        // Simulate sending an alert notification
    }
};

// Subject (Diagnostic System)
class DiagnosticSystem
{
public:
    void attach(DiagnosticObserver *observer)
    {
        observers_.push_back(observer);
    }

    void detach(DiagnosticObserver *observer)
    {
        observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
    }

    void notify(const std::string &diagnosticCode)
    {
        for (auto observer : observers_)
        {
            observer->update(diagnosticCode);
        }
    }

    void generateDiagnosticCode(const std::string &code)
    {
        std::cout << "Diagnostic System: Generating code - " << code << std::endl;
        notify(code);
    }

private:
    std::vector<DiagnosticObserver *> observers_;
};

int main()
{
    DiagnosticSystem diagnosticSystem;

    DiagnosticDisplay display;
    DiagnosticLogger logger;
    DiagnosticAlert alert;

    diagnosticSystem.attach(&display);
    diagnosticSystem.attach(&logger);
    diagnosticSystem.attach(&alert);

    diagnosticSystem.generateDiagnosticCode("P0300"); // Engine Misfire
    diagnosticSystem.generateDiagnosticCode("U0101"); // Lost communication with TCM

    diagnosticSystem.detach(&alert); // removing the alert system.

    diagnosticSystem.generateDiagnosticCode("C1201"); // Engine Control System Malfunction.

    return 0;
}