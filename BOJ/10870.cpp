#include <iostream>
using namespace std;

#define N 25

int dp[N];

int fibo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n]) return dp[n];
    return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << fibo(n);

    return 0;
}