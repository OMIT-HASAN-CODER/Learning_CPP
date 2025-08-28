#include <iostream>

using namespace std;

int main( ) {
    int cups;
    double pricePerCup = 2.5, totalPrice, discount;

    cout << "Enter the number of tea cups: " << endl;
    cin >> cups;

    totalPrice = pricePerCup * cups;

    if (cups > 20) {
        discount = 0.20;
        totalPrice -= totalPrice * discount;
        cout << "You will get 20% discount, total price after discount is: " << totalPrice << endl;
    } else if (cups >= 10 && cups <= 20) {
        discount = 0.10;
        totalPrice -= totalPrice * discount;
        cout << "You will get 10% discount, total price after discount is: " << totalPrice << endl;
    } else {
        discount = 0;
        cout << "Sorry, you will not get any discount, total price is: " << totalPrice << endl;
    }

    return 0;
}