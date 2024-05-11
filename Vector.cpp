#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<typename T>
class Vector {
    vector<T> elements;

public:
    void pushback(const T& item) {
        elements.push_back(item);
    }

    friend ostream& operator<<(ostream& os, const Vector<T>& vec) {
        for (const auto& element : vec.elements) {
            os << element << " ";
        }
        return os;
    }
};

class Device {
public:
    string name;

    friend ostream& operator<<(ostream& os, const Device& device) {
        os << device.name;
        return os;
    }
};

int main() {
    Vector<int> v;
    v.pushback(10);
    v.pushback(20);

    Vector<string> vs;
    vs.pushback("Heyyaa");
    vs.pushback("Hello");

    Vector<Device> vd;
    Device obj1;
    obj1.name = "TV";
    Device obj2;
    obj2.name = "Mobile";
    vd.pushback(obj1);
    vd.pushback(obj2);

    cout << "Vector of intgers: " << v << endl;
    cout << "Vector of strings: " << vs << endl;
    cout << "Vector of Devices: " << vd << endl;

    return 0;
}
