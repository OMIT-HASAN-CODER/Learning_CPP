#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Chai {
private:
    string teaName;
    int servings;
    vector<string> ingredients;

public:
    Chai() {
        teaName = "Unknown Tea";
        servings = 1;
        ingredients = {"Water", "Tea Leaves"};
    }

    Chai(string name, int serve, vector<string> ingr) {
        teaName = name;
        servings = serve;
        ingredients = ingr;
    }

    //getter
    string getTeaName() {
        cout << "Enter Tea Name: " << endl;
        getline(cin, teaName);
        return teaName;
    }

    //setter
    void setTeaName(string name) {
        //logic
        teaName = name;
    }

    //getter for servings
    int getServings() {
        cout << "Enter the number of Servings: " << endl;
        cin >> servings;
        return servings;
    }

    //setter for servings
    void setServings(int serve) {
        servings = serve;
    }

    //getter for ingredients
    vector<string> getingredients() {
        cout << "Enter the name of ingredients: " << endl;
        cin.ignore();
        return ingredients;
    }

    //setter for ingredients
    void setIngredients(vector<string> ingr) {
        ingredients = ingr;
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
    Chai chai;
    cout << "-----Getting Values-----" << endl;
    chai.getTeaName();
    chai.getServings();
    chai.getingredients();
    chai.displayChaiDetails();
    cout << "-----Setting Values-----" << endl;
    chai.setTeaName("Lemon Tea");
    chai.setServings(3);
    chai.setIngredients({"Water", "Tea Leaves", "Lemon", "Honey"});
    chai.displayChaiDetails();
    return 0;
}