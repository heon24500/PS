#include <iostream>
using namespace std;

const int N = 51, M = 51;
int n, m, t;
int mat[N][M];

void rotate(int x, int d, int k) {
	for (int i = x; i <= n; i += x) {
		for (int l = 0; l < k; l++) {
			if (d == 0) {
				int temp = mat[i][m];
				for (int j = m; j > 1; j--) mat[i][j] = mat[i][j - 1];
				mat[i][1] = temp;
			}
			else {
				int temp = mat[i][1];
				for (int j = 1; j < m; j++) mat[i][j] = mat[i][j + 1];
				mat[i][m] = temp;
			}
		}
	}
}

void remove() {
	bool check[N][M] = { 0 };
	bool isExist = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m ; j++) {
			if (mat[i][j] == 0 || mat[i][j] != mat[i][j + 1]) continue;
			check[i][j] = check[i][j + 1] = true;
			isExist = true;
		}
		if (mat[i][m] == 0 || mat[i][m] != mat[i][1]) continue;
		check[i][m] = check[i][1] = true;
		isExist = true;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j < n; j++) {
			if (mat[j][i] == 0 || mat[j][i] != mat[j + 1][i]) continue;
			check[j][i] = check[j + 1][i] = true;
			isExist = true;
		}
	}

	if (isExist) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (check[i][j]) mat[i][j] = 0;
			}
		}
	}
	else {
		int sum = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				sum += mat[i][j];
				if (mat[i][j] != 0) cnt++;
			}
		}
		double avg = (double)sum / cnt;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (mat[i][j] == 0) continue;
				if (mat[i][j] > avg) mat[i][j]--;
				else if (mat[i][j] < avg) mat[i][j]++;
			}
		}
	}
}

void solve(int x, int d, int k) {
	rotate(x, d, k);
	remove();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
		}
	}

	while (t--) {
		int x, d, k;
		cin >> x >> d >> k;
		solve(x, d, k);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans += mat[i][j];
		}
	}
	cout << ans;

	return 0;
}