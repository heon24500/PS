#include <iostream>
using namespace std;

bool check[10];
int a[10];

void solve(int idx, int n, int m) {
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << '\n';
		}
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (check[i]) continue;
		check[i] = true;
		a[idx] = i;
		solve(idx + 1, n, m);
		check[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	solve(0, n, m);

	return 0;
}