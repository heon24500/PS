#include <iostream>
using namespace std;

const int N = 100001;
int a[N], d1[N], d2[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	d1[0] = a[0];
	for (int i = 1; i < n; i++) {
		d1[i] = a[i];
		if (d1[i] < d1[i - 1] + a[i]) d1[i] = d1[i - 1] + a[i];
	}
	d2[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		d2[i] = a[i];
		if (d2[i] < d2[i + 1] + a[i]) d2[i] = d2[i + 1] + a[i];
	}

	int ans = -1000;
	for (int i = 0; i < n; i++) {
		if (ans < d1[i]) ans = d1[i];
	}
	for (int i = 1; i < n - 1; i++) {
		if (ans < d1[i - 1] + d2[i + 1]) ans = d1[i - 1] + d2[i + 1];
	}
	cout << ans;

	return 0;
}