/* 1215. [S/W 문제해결 기본] 3일차 - 회문1 */
#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 1; t <= 10; t++) {
		int len;
		cin >> len;
		int mid = len / 2;

		char table[8][8];
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> table[i][j];
			}
		}

		int cnt = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8 - len + 1; j++) {
				bool flag = true;
				for (int k = 0; k < mid; k++) {
					if (table[i][j + k] != table[i][j + len - k - 1]) flag = false;
				}
				if (flag) cnt++;
			}
		}
		for (int i = 0; i < 8 - len + 1; i++) {
			for (int j = 0; j < 8; j++) {
				bool flag = true;
				for (int k = 0; k < mid; k++) {
					if (table[i + k][j] != table[i + len - k - 1][j]) flag = false;
				}
				if (flag) cnt++;
			}
		}

		cout << "#" << t << " " << cnt << '\n';
	}

	return 0;
}