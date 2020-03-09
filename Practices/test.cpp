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

    return 0;
}