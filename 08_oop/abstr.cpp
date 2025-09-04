#include <iostream>
#include <string>

using namespace std;

class Tea {
public:
    virtual void prepareIngredients() = 0; //pure virtual function
    virtual void brew() = 0;
    virtual void serve() = 0;

    void makeTea() {
        prepareIngredients();
        brew();
        serve();
    }
};

//derived class
class GreenTea : public Tea {
public:
    void prepareIngredients() override {
        cout << "Green leaves and water is ready." << endl;
    }

    void brew() override {
        cout << "Green tea brewed" << endl;
    }

    void serve() override {
        cout << "Green tea Served." << endl;
    }
};

class MasalaTea : public Tea {
public:
    void prepareIngredients() override {
        cout << "Tea leaves and water is ready with masala." << endl;
    }

    void brew() override {
        cout << "Masala tea brewed" << endl;
    }

    void serve() override {
        cout << "Masala tea Served." << endl;
    }
};

int main() {
    GreenTea greenTea;
    greenTea.makeTea();

    MasalaTea masalaTea;
    masalaTea.makeTea();
    return 0;
}