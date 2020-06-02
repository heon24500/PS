#include <iostream>
using namespace std;

int n, s, ret = 0, nums[20];

void solve(int sum, int idx) {
	if (idx == n) {
		if (sum == s) ret++;
		return;
	}

	solve(sum + nums[idx], idx + 1);
	solve(sum, idx + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	if (s == 0) ret--;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	
	solve(0, 0);
	cout << ret;

	return 0;
}