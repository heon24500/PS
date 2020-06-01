#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> dp;

int calc(int n) {
    if (n == 1) return 0;
    if (dp[n] != -1) return dp[n];

    int result = calc(n - 1) + 1;

    if (n % 3 == 0) result = min(result, calc(n / 3) + 1);
    if (n % 2 == 0) result = min(result, calc(n / 2) + 1);

    dp[n] = result;

    return result;
}

int main() {
    int n;
    cin >> n;
    dp.resize(n + 1, -1);

    cout << calc(n);

    return 0;
}