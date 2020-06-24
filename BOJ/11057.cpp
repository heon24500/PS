#include <iostream>
using namespace std;

const int N = 1001;
const int mod = 10007;
long long d[N][10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i <= 9; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i < N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] += d[i - 1][k];
				d[i][j] %= mod;
			}
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