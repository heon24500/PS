#include <iostream>
#include <algorithm>
using namespace std;

bool check[10];
int a[10], num[10];

void solve(int idx, int start, int n, int m) {
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << num[a[i]] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < n; i++) {
		if (check[i]) continue;
		check[i] = true;
		a[idx] = i;
		solve(idx + 1, i + 1, n, m);
		check[i] = false;
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
	solve(0, 0, n, m);

	return 0;
}