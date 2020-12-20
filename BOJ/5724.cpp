#include <iostream>
using namespace std;

const int N = 101;
int dp[N];

int solve(int n) {
    if (n == 1) return dp[1] = 1;
    if (dp[n]) return dp[n];
    return dp[n] = n * n + solve(n - 1);
}

int main() {
    while (true) {
        int num;
        cin >> num;
        if (num == 0) break;
        cout << solve(num) << '\n';
    }
    
    return 0;
}