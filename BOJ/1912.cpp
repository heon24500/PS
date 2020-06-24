#include <iostream>
using namespace std;

const int N = 100001;
int a[N], d[N];

int main() {
	int n, ans = -1000;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		d[i] = a[i];
		if (d[i] < d[i - 1] + a[i]) d[i] = d[i - 1] + a[i];
		if (ans < d[i]) ans = d[i];
	}
	cout << ans;

	return 0;
}