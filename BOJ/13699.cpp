#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	long long dp[36];
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = 0;
		for (int j = 0; j < i; j++) dp[i] += dp[j] * dp[i - j - 1];
	}
	cout << dp[n];

	return 0;
}