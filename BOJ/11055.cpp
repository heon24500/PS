#include <iostream>
using namespace std;

const int N = 1001;
int a[N], d[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		d[i] = a[i];
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && d[i] < d[j] + a[i]) d[i] = d[j] + a[i];
		}
		if (ans < d[i]) ans = d[i];
	}

	cout << ans;

	return 0;
}