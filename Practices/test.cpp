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

struct info {
    string name, address;
    int age;
    info(string _name, string _address, int _age) : name(_name), address(_address), age(_age) {
        cout << "constructed" << endl;
    }
    info(info&& p) : name(move(p.name)), address(move(p.address)), age(p.age) {
        cout << "copied" << endl;
    }
};

int main() {
    vector<info> stu;
    cout << "emplace_back\n";
    stu.emplace_back("Tony", "Hometown", 12);
    cout << "------------------\n" << "push_back\n";
    stu.push_back(info("Mike", "New York", 15));
    return 0;
}