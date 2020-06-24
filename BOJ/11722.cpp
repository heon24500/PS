#include <iostream>
using namespace std;

const int N = 1001;
int a[N], d[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		d[i] = 1;
		for (int j = n - 1; j > i; j--) {
			if (a[i] > a[j] && d[i] < d[j] + 1) d[i] = d[j] + 1;
		}
		if (ans < d[i]) ans = d[i];
	}

	cout << ans;

	return 0;
}