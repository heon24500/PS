#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int num, mod;
        cin >> num;
        if (num == 1000) mod = 10000;
        else if (num > 100) mod = 1000;
        else if (num > 10) mod = 100;
        else mod = 10;

        if ((num * num) % mod == num) cout << "YES\n";
        else cout << "NO\n";
    }
}