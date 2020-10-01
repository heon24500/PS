#include <iostream>
using namespace std;

const int N = 50, M = 50;
int n, m;
int a[N], b[M];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	int idx = 0;
	for (int i = 0; i < m; i++) {
		while (a[idx] < b[i]) idx++;
		a[idx] -= b[i];
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	cout << sum;

	return 0;
}