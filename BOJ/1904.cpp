/* 1904. 01≈∏¿œ */
#include <iostream>
using namespace std;

const int N = 1000001;
const int mod = 15746;
int dp[N];

int main()
{
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
	}

	cout << dp[n];

	return 0;
}