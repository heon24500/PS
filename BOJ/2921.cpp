#include <iostream>
using namespace std;

const int N = 1001;
int dp[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		for (int j = i; j <= 2 * i; j++) {
			dp[i] += j;
		}
	}
	cout << dp[n];

	return 0;
}