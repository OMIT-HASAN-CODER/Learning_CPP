#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Chai {
public:
    string teaName;
    int servings;
    vector<string> ingredients;

    //delegating constructor
    Chai(string name) : Chai(name, 1, {"Water", "Tea Leaves"}) {}

    //main constructor
    Chai(string name, int serve, vector<string> ingr) {
        teaName = name;
        servings = serve;
        ingredients = ingr;

        cout << "Main Constructor called!" << endl;
    }

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
    Chai quickChai("Quick Chai");
    quickChai.displayChaiDetails();

    return 0;
}