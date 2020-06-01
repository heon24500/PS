#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    int val = 1, sum = 0;
    while (T > 0) {
        sum += (T % 9) * val;
        T /= 9;
        val *= 10;
    }

    cout << sum;
}