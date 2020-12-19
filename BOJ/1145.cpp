#include <iostream>
using namespace std;

int ans;

void solve(int arr[], int target[]) {
	for (int i = 0; i < 5; i++) {
		if (ans != 0 && arr[i] >= ans) continue;

		int cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (arr[i] % target[j] == 0) cnt++;
		}
		if (cnt >= 3) {
			if (ans == 0) ans = arr[i];
			else ans = min(ans, arr[i]);
		}
	}

	bool flag = false;
	for (int i = 0; i < 5; i++) {
		if (ans != 0 && arr[i] >= ans) continue;
		int cnt = arr[i] / target[i];
		arr[i] = target[i] * (cnt + 1);
		flag = true;
	}
	if (flag) solve(arr, target);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[5], target[5];
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		target[i] = arr[i];
	}

	solve(arr, target);
	cout << ans;

	return 0;
}