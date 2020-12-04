#include <iostream>
using namespace std;

const int N = 16;
int t, n, ans;
int s[N][N];
bool check[N];

void solve(int depth, int idx) {
	if (depth == n / 2) {
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (check[i] && check[j]) sum1 += s[i][j] + s[j][i];
				if (!check[i] && !check[j]) sum2 += s[i][j] + s[j][i];
			}
		}
		int diff = abs(sum1 - sum2);
		ans = min(ans, diff);

		return;
	}

	for (int i = idx; i < n; i++) {
		check[i] = true;
		solve(depth + 1, i + 1);
		check[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> s[i][j];
			}
		}

		ans = 1e9;
		solve(0, 0);
		cout << "#" << tc << " " << ans << '\n';
	}

	return 0;
}