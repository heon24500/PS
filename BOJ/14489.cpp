#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long A, B, C;
    cin >> A >> B >> C;

    long sum = A + B;
    if (sum >= 2 * C) cout << sum - 2 * C;
    else cout << sum;
}