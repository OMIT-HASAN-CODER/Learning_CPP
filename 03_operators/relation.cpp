#include <iostream>

using namespace std;

int main() {
    int cups;

    cout << "Enter the number of cups you have: " << endl;
    cin >> cups;

    if (cups > 20) {
        cout << "You will get a gold badge." << endl;
    } else if (cups >= 10 && cups <= 20) {
        cout << "You will get a silver badge." << endl;
    } else {
        cout << "Sorry, you will not get any badge." << endl;
    }

    return 0;
}