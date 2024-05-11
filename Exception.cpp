#include <iostream>
#include <string>
using namespace std;

int divFun(int numerator, int divisor) {
    cout << "Div Begin" << endl;
    if (divisor == 0) {
        throw runtime_error("Division by zero");
    }
    int result = numerator / divisor;
    cout << "Div End" << endl;
    return result;
}

void init() {
    cout << "Init Begin" << endl;
    int result;
    try {
        result = divFun(10, 0);
    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
        result = 0; // or handle it in another  way
    }
    cout << "Init End" << ":" << result << endl;
}

int main(){
    cout<<"Begin of main"<<endl;
    init();
    cout<<"End of main"<<endl;
    return 0;
}