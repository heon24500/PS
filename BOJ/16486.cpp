#include <iostream>
using namespace std;

int main() {
    int d1, d2;
    cin >> d1 >> d2;

    double result = (2 * d1) + (2 * 3.141592 * d2);

    cout << fixed;
    cout.precision(6);
    cout << result;

    return 0;
}