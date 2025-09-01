#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Chai {
public:
    //data members (attributes)
    string teaName; //name of the tea
    int servings; //number of servings
    vector<string> ingredients; //list of ingredients for the tea

    //member function
    void displayChaiDetails() {
        cout << "Tea Name: " << teaName << endl;
        cout << "Tea Servings: " << servings << endl;
        cout << "Ingredients: ";
        for (string ingredient : ingredients) {
            cout << ingredient << " ";
        }
        cout << endl;
    }
};

int main() {
    Chai chaiOne;
    chaiOne.teaName = "Lemon Tea";
    chaiOne.servings = 2;
    chaiOne.ingredients = {"Water", "Lemon", "Honey", "Tea"};
    chaiOne.displayChaiDetails();
    return 0;
}