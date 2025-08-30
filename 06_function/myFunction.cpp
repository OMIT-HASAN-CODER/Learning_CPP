#include <iostream>
#include <string>

using namespace std;

int checkTemperature(int temperature) {
    return temperature;
}

//declaration of function
void serveChai(int cups);

void makeChai() {
    cout << "Boiling water, adding tea leaves, straining..." << endl;
}

void serveChai(string teaType = "Masala Tea") {
    int cups = 8;
    cout << "Serving " << teaType << endl;
}

int main() {
    int temp = checkTemperature(50);
    cout << temp << endl;
    makeChai(); //calling a function
    serveChai(3);
    serveChai();
    return 0;
}

//definition of function
void serveChai(int cups) {
    cout << "Serving " << cups << " of chai" << endl;
}
