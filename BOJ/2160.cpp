#include <iostream>
using namespace std;

const int N = 51;
int n, min_cnt = 1e9, ans1 = -1, ans2 = -1;
char mat[N][5][7];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 7; x++) {
				cin >> mat[i][y][x];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int cnt = 0;
			for (int y = 0; y < 5; y++) {
				for (int x = 0; x < 7; x++) {
					if (mat[i][y][x] != mat[j][y][x]) cnt++;
				}
			}
			if (min_cnt > cnt) {
				min_cnt = cnt;
				ans1 = i;
				ans2 = j;
			}
		}
	}

	cout << ans1 << " " << ans2;

	return 0;
}