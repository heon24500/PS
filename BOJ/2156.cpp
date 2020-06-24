#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10001;
int a[N], d[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	d[1] = a[1];
	d[2] = a[1] + a[2];
	for (int i = 3; i <= n; i++) {
		d[i] = max(max(d[i - 1], d[i - 2] + a[i]), d[i - 3] + a[i] + a[i - 1]);
	}
	cout << d[n];

	return 0;
}