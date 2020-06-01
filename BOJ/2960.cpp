#include <iostream>
using namespace std;

int arr[1001];

bool is_sosu(int n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int num = 2, cnt = 0, ret = 0;
	while (cnt != k) {
		if (is_sosu(num)) {
			for (int i = 1; i * num <= n; i++) {
				if (arr[i * num]) continue;
				ret = i * num;
				arr[i * num] = 1;
				cnt++;
				if (cnt == k) break;
			}
		}
		num++;
	}
	cout << ret;

	return 0;
}