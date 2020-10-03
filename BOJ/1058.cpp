#include <iostream>
using namespace std;

const int N = 50;
int n;
char mat[N][N];
int f[N][N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || mat[i][j] == 'N') continue;
			f[i][j] = 1;
			for (int k = 0; k < n; k++) {
				if (i == k) continue;
				if (mat[j][k] == 'Y') f[i][k] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (f[i][j]) cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;

	return 0;
}