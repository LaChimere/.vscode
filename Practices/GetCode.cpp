#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    srand((unsigned)time(NULL));
    double x = double(rand()) / RAND_MAX;
    x *= 1000000;
    cout << x;
    return 0;
}