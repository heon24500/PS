#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    double K, D1, D2, H;
    cin >> K >> D1 >> D2;

    double d = (D1 - D2) / 2;
    if (d == 0) H = K * K;
    else H = K * K - d * d;

    cout << H;
}