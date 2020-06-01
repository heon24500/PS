#include <iostream>
#include <algorithm>
using namespace std;

#define N 15
#define K 100000005

int a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ret = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (k < a[i]) continue;
		int coin = k / a[i];
		ret += coin;
		k -= coin * a[i];
		if (k == 0) break;
	}
	cout << ret;

	return 0;
}