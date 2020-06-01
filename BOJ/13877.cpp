#include <iostream>
using namespace std;

int digit(int n, int j) {
    int val = 1, ret = 0;

    while (n > 0) {
        if (n % 10 >= j) return 0;
        ret += (n % 10) * val;
        n /= 10;
        val *= j;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int k, num;
        cin >> k >> num;

        cout << k << " " << digit(num, 8) << " " << num << " " << digit(num, 16) << "\n";
    }
}