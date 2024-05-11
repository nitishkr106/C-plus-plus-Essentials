#include <iostream>
#include <string>
using namespace std;

void modifyString(string &arg){    // modifyString function to reverse the string
    // Reverse the string
    int n = arg.length();
    for(int i = 0; i < n / 2; i++) {
        char temp = arg[i];
        arg[i] = arg[n - i - 1];
        arg[n - i - 1] = temp;
    }
}

void modifyStringAndPrint(const string* const arg){  // Function to print the reversed string
    string temp = *arg; // Copy the string to avoid modifying the original
    modifyString(temp); // Reverse the copied string
    cout << "Reversed string is: " << temp << endl; // Print the reversed string
}

int main(){
    string data="h1";
    modifyString(data); // Reverse the string
    cout << data << endl; // Print the reversed string

    modifyStringAndPrint(&data); // Pass the string pointer and print the reversed string

    return 0;
}
