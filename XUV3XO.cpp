#include<iostream>
#include<string>
using namespace std;

// Abstraction
class IEngine {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
};

// Low-level module
class FuelInjectedEngine : public IEngine {
public:
    void start() { cout << "Fuel-injected engine start" << endl; }
    void stop() { cout << "Fuel-injected engine stop" << endl; }
};

// Low-level module
class DirectInjectionEngine : public IEngine {
public:
    void start() { cout << "Direct injection engine start" << endl; }
    void stop() { cout << "Direct injection engine stop" << endl; }
};

// High-level module
class XUV3X0 {

    // Dependency (abstract)
    IEngine* engine; // High module doesn't depend on low module (loosely coupled)
public:
    // Constructor dependency injection
    XUV3X0(IEngine* engineArg) : engine{ engineArg } {}

    void drive() {
        this->engine->start();
    }
    void halt() {
        this->engine->stop();
    }
};

int main() {

    FuelInjectedEngine napEngine;
    DirectInjectionEngine turboEngine;
    XUV3X0 car{ &napEngine };
    car.drive();
    XUV3X0 turboCar{ &turboEngine };
    turboCar.drive();

    return 0;
}
