#include <iostream>
using namespace std;

#define N 1000005

int a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, b, c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> b >> c;

	long sum = n;
	for (int i = 0; i < n; i++) {
		if (a[i] > b) a[i] -= b;
		else a[i] = 0;

		if (a[i] % c == 0) sum += a[i] / c;
		else sum += a[i] / c + 1;
	}

	cout << sum;

	return 0;
}