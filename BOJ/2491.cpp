#include <iostream>
using namespace std;

const int N = 100000;
int n, ret;
int arr[N], dp[N][2];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i][0] = dp[i][1] = 1;
		if (i != 0 && arr[i] >= arr[i - 1]) dp[i][0] = dp[i - 1][0] + 1;
		if (i != 0 && arr[i] <= arr[i - 1]) dp[i][1] = dp[i - 1][1] + 1;
		if (ret < dp[i][0]) ret = dp[i][0];
		if (ret < dp[i][1]) ret = dp[i][1];
	}

	cout << ret;

	return 0;
}