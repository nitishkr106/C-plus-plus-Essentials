#include<iostream>
#include<string>
using namespace std;

// Abstract base class for devices
class Device {
private:
    string name;
    string model;
    string version;

protected:
    // Constructor
    Device(const string& nameArg, const string& modelArg, const string& versionArg)
        : name(nameArg), model(modelArg), version(versionArg) {
        cout << "Device constructor called" << endl;
    }

    // Destructor
    ~Device() {
        cout << "Device Destructed" << endl;
    }
};

// Interface for printing functionality
class IPrint {
public:
    virtual void print(const string& content) = 0;
};

// Interface for scanning functionality
class IScan {
public:
    virtual void scan(const string& content) = 0;
};

// Printer class implementing IPrint interface
class Printer : public IPrint, public Device {
public:
    // Constructor
    Printer() : Device("", "", "") {
        cout << "Printer constructor called" << endl;
    }

    // Destructor
    ~Printer() {
        cout << "Printer Destructed" << endl;
    }

    // Print method
    void print(const string& content) override {
        cout << "Print " << content << endl;
    }
};

// Scanner class implementing IScan interface
class Scanner : public IScan, public Device {
public:
    // Constructor
    Scanner() : Device("", "", "") {
        cout << "Scanner constructor called" << endl;
    }

    // Destructor
    ~Scanner() {
        cout << "Scanner Destructed" << endl;
    }

    // Scan method
    void scan(const string& content) override {
        cout << "Scan " << content << endl;
    }
};

// PrintScanner class implementing IPrint and IScan interfaces
class PrintScanner : public Device, public IPrint, public IScan {
public:
    // Constructor
    PrintScanner(const string& name, const string& model, const string& version)
        : Device(name, model, version) {
        cout << "PrintScanner constructor called" << endl;
    }

    // Destructor
    ~PrintScanner() {
        cout << "PrintScanner Destructed" << endl;
    }

    // Print method
    void print(const string& content) override {
        cout << "Print " << content << endl;
    }

    // Scan method
    void scan(const string& content) override {
        cout << "Scan " << content << endl;
    }
};

// TaskManager class for managing print and scan tasks
class TaskManager {
public:
    // Invoke print task
    void invokePrintTask(IPrint* printerPtr, const string& content) {
        printerPtr->print(content);
    }

    // Invoke scan task
    void invokeScanTask(IScan* scannerPtr, const string& content) {
        scannerPtr->scan(content);
    }
};

int main() {
    // Create PrintScanner object
    PrintScanner hpPrintScanner("HP", "OfficeJet", "v2");

    // Initialize TaskManager
    TaskManager taskMgr;

    // Invoke print and scan tasks using PrintScanner object
    taskMgr.invokePrintTask(&hpPrintScanner, "doc.pdf");
    taskMgr.invokeScanTask(&hpPrintScanner, "doc.pdf");

    return 0;
}
