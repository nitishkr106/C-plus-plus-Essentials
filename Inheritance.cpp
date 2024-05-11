#include <iostream>
#include <string>
using namespace std;

// Base class for  Laptop
class Laptop {
protected:
    string model;
    string serialNumber;
    string color;
    float weight;
    string operatingSystem;
    int storageCapacity;

public:
    // Parameterized constructor
    Laptop(const string& model, const string& serial, const string& color, float weight, 
           const string& os, int storage)
        : model(model), serialNumber(serial), color(color), weight(weight),
          operatingSystem(os), storageCapacity(storage) {}

    // Getter methods
    string getModel() const { return model; }
    string getSerialNumber() const { return serialNumber; }
    string getColor() const { return color; }
    float getWeight() const { return weight; }
    string getOperatingSystem() const { return operatingSystem; }
    int getStorageCapacity() const { return storageCapacity; }
};

// Derived class representing an HP Laptop
class HPLaptop : public Laptop {
public:
    // Constructor calling base class constructor
    HPLaptop(const string& model, const string& serial, const string& color, float weight, 
             const string& os, int storage)
        : Laptop(model, serial, color, weight, os, storage) {}
};

int main() {
    // Example usage
    HPLaptop hpLaptop("Pavilion", "12345", "Silver", 2.3, "Windows", 512);
    
    // Output laptop details
    cout << "Model: " << hpLaptop.getModel() << endl;
    cout << "Serial Number: " << hpLaptop.getSerialNumber() << endl;
    cout << "Color: " << hpLaptop.getColor() << endl;
    cout << "Weight: " << hpLaptop.getWeight() << " kg" << endl;
    cout << "Operating System: " << hpLaptop.getOperatingSystem() << endl;
    cout << "Storage Capacity: " << hpLaptop.getStorageCapacity() << "GB" << endl;

    return 0;
}
