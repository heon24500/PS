#include <iostream>
using namespace std;

const int N = 1001;
int a[N], d1[N], d2[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		d1[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && d1[i] < d1[j] + 1) d1[i] = d1[j] + 1;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		d2[i] = 1;
		for (int j = n - 1; j > i; j--) {
			if (a[i] > a[j] && d2[i] < d2[j] + 1) d2[i] = d2[j] + 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans < d1[i] + d2[i] - 1) ans = d1[i] + d2[i] - 1;
	}
	cout << ans;

	return 0;
}