#include <iostream>
using namespace std;

int main() {
    int A, B, C, D, P;
    cin >> A >> B >> C >> D >> P;

    int X = A * P;
    int Y = B;
    if (P > C) {
        int diff = P - C;
        Y += diff * D;
    }

    if (X > Y) cout << Y;
    else cout << X;

    return 0;
}