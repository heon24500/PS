#include <iostream>
using namespace std;

const int N = 101;
const long long mod = 1000000000;
long long d[N][10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			d[i][j] = 0;
			if (j - 1 >= 0) d[i][j] += d[i - 1][j - 1];
			if (j + 1 <= 9) d[i][j] += d[i - 1][j + 1];
			d[i][j] %= mod;
		}
	}

	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += d[n][i];
		ans %= mod;
	}
	cout << ans;

	return 0;
}