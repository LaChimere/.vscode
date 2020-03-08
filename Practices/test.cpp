#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <bitset>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

template<typename T> void print_queue(T& q) {
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

struct fruit {
    string name;
    int price;
    fruit(string _name, int _price) : name(_name), price(_price) {}
    friend bool operator<(const fruit& f1, const fruit& f2) {
        return f1.price > f2.price;
    }
};

int main() {
    priority_queue<fruit> q;
    fruit f1("Apple", 3);
    fruit f2("Pear", 4);
    fruit f3("Peach", 1);
    q.push(f1);
    q.push(f2);
    q.push(f3);
    while (!q.empty()) {
        cout << q.top().name << " : " << q.top().price << endl;
        q.pop();
    }
    return 0;
}