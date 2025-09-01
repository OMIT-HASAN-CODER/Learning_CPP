#include <iostream>

using namespace std;

int main() {
    int chaiSales[3][7] = {
        {50, 60, 55, 70, 65, 80, 75},
        {40, 55, 60, 65, 70, 75, 80},
        {45, 50, 55, 60, 65, 70, 75 }
    };

    for (int i = 0; i < 3; i++) {
        cout << "I am at shop: " << i + 1 << endl;
        for (int j = 0; j < 7; j++) {
            cout << chaiSales[i][j] << " cups" << endl;
        }
    }

    return 0;
}