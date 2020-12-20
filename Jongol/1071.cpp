#include <iostream>
using namespace std;

int main() {
	int arr[40];
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> m;

	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i++) {
		if (m % arr[i] == 0) ans1 += arr[i];
		if (arr[i] % m == 0) ans2 += arr[i];
	}
	cout << ans1 << "\n" << ans2;

	return 0;
}