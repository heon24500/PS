/* 1209. [S/W 문제해결 기본] 2일차 - Sum */
#include <iostream>
using namespace std;

int arr[100][100];
int column_sum[100];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 1; t <= 10; t++) {
		int t_num;
		cin >> t_num;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
			}
		}

		int ret = -1;
		int lr_sum = 0, rl_sum = 0;
		for (int i = 0; i < 100; i++) {
			int row_sum = 0;
			for (int j = 0; j < 100; j++) {
				row_sum += arr[i][j];
				column_sum[j] += arr[i][j];
				if (i == j) lr_sum += arr[i][j];
				if (i == (99 - j)) rl_sum += arr[i][j];
			}
			if (ret == -1) ret = row_sum;
			else if (ret < row_sum) ret = row_sum;
		}

		for (int i = 0; i < 100; i++) {
			if (ret < column_sum[i]) ret = column_sum[i];
			column_sum[i] = 0;
		}

		if (ret < lr_sum) ret = lr_sum;
		if (ret < rl_sum) ret = rl_sum;

		cout << "#" << t_num << " " << ret << '\n';
	}

	return 0;
}