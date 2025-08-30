#include <iostream>

using namespace std;

int checkTemperature(int temperature) {
    return temperature;
}

//declaration of function
void serveChai(int cups);

int main() {
    int temp = checkTemperature(50);
    cout << temp << endl;

    serveChai(3);
    return 0;
}

//definition of function
void serveChai(int cups) {
    cout << "Serving " << cups << " of chai";
}
