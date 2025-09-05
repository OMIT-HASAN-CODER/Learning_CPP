#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <ctime>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Product {
    int productID;
    string name;
    string category;
};

struct Order {
    int orderID;
    int productID;
    int quantity;
    string customerID;
    time_t orderDate;
};

int main() {
    vector<Product> products = {
        {101, "Laptop", "Electronics"},
        {102, "Smart Phone", "Electronics"},
        {103, "Coffe Maker", "Kitchen"},
        {104, "Blender", "Kitchen"},
        {105, "Desk Lamp", "Home"}
    };

    deque<string> recentCustomers = {"C001", "C002", "C003", "C004"};

    recentCustomers.push_front("C000");
    recentCustomers.push_back("C005");

    list<Order> orderHistory;

    orderHistory.push_back({1, 101, 1, "C000", time(0)});
    orderHistory.push_back({2, 102, 2, "C001", time(0)});
    orderHistory.push_back({3, 103, 1, "C002", time(0)});

    set<string> categories;

    for (const auto &product: products) {
        categories.insert(product.category);
    }

    map<int, int> productStock = {
        {101, 10},
        {102, 20},
        {103, 15},
        {104, 5},
        {105, 7}
    };

    multimap<string, Order> customerOrders;
    for (const auto &order: orderHistory) {
        customerOrders.insert({order.customerID, order});
    }

    unordered_map<string, string> customerData = {
        {"C000", "Alice"},
        {"C001", "Omit"},
        {"C002", "Hasan"},
        {"C003", "Anik"},
        {"C004", "Naeem"},
        {"C005", "Melisa"}
    };

    unordered_set<int> uniqueProductIDs;

    for (const auto &product: products) {
        uniqueProductIDs.insert(product.productID);
    }

    return 0;
}