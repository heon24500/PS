#include <iostream>
using namespace std;

const int N = 1000001;
const long long mod = 1000000009LL;
long long d[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	d[0] = 1;
	for (int i = 1; i < N; i++) {
		if (i >= 1) d[i] += d[i - 1];
		if (i >= 2) d[i] += d[i - 2];
		if (i >= 3) d[i] += d[i - 3];
		d[i] %= mod;
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}

	return 0;
}