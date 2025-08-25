#include <iostream>

using namespace std;

int main() {
    cout << "Welcome to Chai with cpp." << endl;

    int score;
    score = 110;

    const int uid = 123456789;

    int balance = 500;
    balance += 1000;

    cout << "Score: " << score << endl;
    cout << "Uid: " << uid << endl;
    cout << "Balance: " << balance << endl;

    return 0;
}