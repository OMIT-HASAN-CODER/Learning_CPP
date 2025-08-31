#include <iostream>

using namespace std;

int main() {
    int chaiTemperature[5] = {85, 90, 88, 92, 89};

    cout << "Chai temperature: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << chaiTemperature[i] << " degree C" << endl;
    }

    return 0;
}