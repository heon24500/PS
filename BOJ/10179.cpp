#include <iostream>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        double price;
        cin >> price;

        price *= 0.8;
        cout << fixed;
        cout.precision(2);
        cout << "$" << price << endl;
    }

    return 0;
}