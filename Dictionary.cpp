#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename K, typename V>
class Dictionary {
private:
    struct KeyValue {
        K key;
        V value;
    };

    std::vector<KeyValue> data;

public:
    // Insert or update key-value pair
    void insert(const K& key, const V& value) {
        for (auto& kv : data) {
            if (kv.key == key) {
                kv.value = value;
                return;
            }
        }
        data.push_back({ key, value });
    }

    // Get value by key
    V& operator[](const K& key) {
        for (auto& kv : data) {
            if (kv.key == key) {
                return kv.value;
            }
        }
        throw std::out_of_range("Key not found");
    }

    // Get number of key-value pairs
    size_t size() const {
        return data.size();
    }

    friend std::ostream& operator<<(std::ostream& os, const Dictionary<K, V>& dict) {
        os << "{ ";
        for (const auto& kv : dict.data) {
            os << kv.key << ": " << kv.value << ", ";
        }
        os << "}";
        return os;
    }
};

int main() {
    Dictionary<std::string, int> dict;

    dict.insert("carrot", 10);
    dict.insert("broccoli", 20);
    dict.insert("spinach", 15);

    std::cout << "Size of dictionary: " << dict.size() << std::endl;

    std::cout << "Value of 'carrot': " << dict["carrot"] << std::endl;
    std::cout << "Value of 'broccoli': " << dict["broccoli"] << std::endl;

    dict["broccoli"] = 25;
    std::cout << "Updated value of 'broccoli': " << dict["broccoli"] << std::endl;

    cout << "The whole dictionary will look like this: " << endl;
    cout << dict;

    return 0;
}
