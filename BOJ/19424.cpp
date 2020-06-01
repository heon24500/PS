#include <iostream>
using namespace std;

int main() {
    int S, T, D, F, hour;
    cin >> S >> T >> D;

    hour = D / (S * 2);
    F = hour * T;

    cout << F;

    return 0;
}