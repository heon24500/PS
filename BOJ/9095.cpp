#include <iostream>
using namespace std;

#define N 15

int cache[N];

int dp(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    if (cache[n]) return cache[n];
    return cache[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp(n) << "\n";
    }

    return 0;
}