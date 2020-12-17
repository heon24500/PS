#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, ans = 0;
	cin >> n;

	int arr[1000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		int j = i;
		while (j - 1 >= 0) {
			if (arr[j - 1] >= arr[j]) break;
			j--;
		}
		if (j != i) ans = max(ans, arr[i] - arr[j]);
	}
	cout << ans;

	return 0;
}