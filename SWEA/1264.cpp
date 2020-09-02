/* 1264. [S/W 문제해결 응용] 8일차 - 이미지 유사도 검사 */
#include <iostream>
#include <vector>
using namespace std;

const int N = 501;
int lcs[N][N];

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			lcs[i][j] = 0;
		}
	}
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n;
		cin >> n;
		vector<char> str1(n), str2(n);
		for (int i = 0; i < n; i++) {
			cin >> str1[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> str2[i];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (str1[i] == str2[j]) lcs[i + 1][j + 1] = lcs[i][j] + 1;
				else lcs[i + 1][j + 1] = max(lcs[i][j + 1], lcs[i + 1][j]);
			}
		}

		double ret = (double)lcs[n][n] / n;
		ret *= 100;

		cout << fixed;
		cout.precision(2);
		cout << "#" << tc << " " << ret << '\n';
		init();
	}

	return 0;
}