#include <iostream>
#include <string>
using namespace std;

class Location {
private:
    string cityName;
    float latitude;

public:
    Location() {}
    Location(string name, float coord) : cityName(name), latitude(coord) {}

    string getCityName() {
        return cityName;
    }

    void setCityName(string name) {
        cityName = name;
    }
};

class LocationDataReader {
private:
    string filePath;

public:
    LocationDataReader(string path) : filePath(path) {}
};

int main() {
    // Stack objects/allocation
    Location city1("Bangalore", 12.9716);
    cout << "City: " << city1.getCityName() << endl;

    // Heap allocation
    Location* city2 = new Location("Delhi", 28.7041);
    cout << "City: " << city2->getCityName() << endl;
    delete city2;

    return 0;
}
