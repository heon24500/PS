#include <iostream>
#include <algorithm>
using namespace std;

#define N 100005
#define INF 1e9

int dp[N][5][5];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int nums[N], n = 0;
	while (true) {
		cin >> nums[n];
		if (nums[n] == 0) break;
		n++;
	}

	dp[1][nums[0]][0] = 2;
	dp[1][0][nums[0]] = 2;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 4; j++) {
			for (int k = 0; k <= 4; k++) {
				if (!dp[i - 1][j][k]) continue;
				int add, push = nums[i - 1];

				// 왼발로 이동
				if (j == 0) add = 2;
				else if (j == push) add = 1;
				else {
					if (abs(push - j) == 2) add = 4;
					else add = 3;
				}
				if (!dp[i][push][k]) dp[i][push][k] = dp[i - 1][j][k] + add;
				else dp[i][push][k] = min(dp[i][push][k], dp[i - 1][j][k] + add);

				// 오른발로 이동
				if (k == 0) add = 2;
				else if (k == push) add = 1;
				else {
					if (abs(push - k) == 2) add = 4;
					else add = 3;
				}
				if (!dp[i][j][push]) dp[i][j][push] = dp[i - 1][j][k] + add;
				else dp[i][j][push] = min(dp[i][j][push], dp[i - 1][j][k] + add);
			}
		}
	}

	int min = INF;
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 4; j++) {
			if (!dp[n][i][j]) continue;
			if (min > dp[n][i][j]) min = dp[n][i][j];
		}
	}

	cout << min;

	return 0;
}