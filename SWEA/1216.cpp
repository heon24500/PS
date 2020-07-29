/* 1216. [S/W 문제해결 기본] 3일차 - 회문2 */
#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 1; t <= 10; t++) {
		int t_num;
		cin >> t_num;

		char table[100][100];
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> table[i][j];
			}
		}

		int max_len = 1;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				for (int k = 99; k >= j; k--) {
					int len = k - j + 1;
					int mid = len / 2;
					bool flag = true;
					for (int l = 0; l < mid; l++) {
						if (table[i][j + l] != table[i][j + len - l - 1]) flag = false;
					}
					if (flag) {
						if (max_len < len) max_len = len;
						break;
					}
				}
			}
		}
		
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				for (int k = 99; k >= i; k--) {
					int len = k - i + 1;
					int mid = len / 2;
					bool flag = true;
					for (int l = 0; l < mid; l++) {
						if (table[i + l][j] != table[i + len - l - 1][j]) flag = false;
					}
					if (flag) {
						if (max_len < len) max_len = len;
						break;
					}
				}
			}
		}

		cout << "#" << t_num << " " << max_len << '\n';
	}

	return 0;
}