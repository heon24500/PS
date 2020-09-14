#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int N = 101;
int n;
int dp[N];
pii lines[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> lines[i].first >> lines[i].second;
	}
	sort(lines, lines + n);

	int ret = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (lines[i].second > lines[j].second) {
				if (dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
			}
		}
		if (ret < dp[i]) ret = dp[i];
	}
	cout << n - ret;


	return 0;
}