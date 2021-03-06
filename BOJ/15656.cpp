#include <iostream>
#include <algorithm>
using namespace std;

int a[10], num[10];

void solve(int idx, int n, int m) {
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << num[a[i]] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		a[idx] = i;
		solve(idx + 1, n, m);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	solve(0, n, m);

	return 0;
}