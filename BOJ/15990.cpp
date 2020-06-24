#include <iostream>
using namespace std;

const int N = 100001;
const long long mod = 1000000009;
long long d[N][4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i < N; i++) {
		if (i - 1 >= 0) {
			d[i][1] = d[i - 1][2] + d[i - 1][3];
			if (i == 1) d[i][1] = 1;
		}
		if (i - 2 >= 0) {
			d[i][2] = d[i - 2][1] + d[i - 2][3];
			if (i == 2) d[i][2] = 1;
		}
		if (i - 3 >= 0) {
			d[i][3] = d[i - 3][1] + d[i - 3][2];
			if (i == 3) d[i][3] = 1;
		}

		for (int j = 1; j <= 3; j++) {
			d[i][j] %= mod;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long ans = 0;
		for (int i = 1; i <= 3; i++) {
			ans += d[n][i];
			ans %= mod;
		}
		cout << ans << '\n';
	}

	return 0;
}