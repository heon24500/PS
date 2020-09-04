#include <iostream>
using namespace std;

const int N = 15;
int n, max_benefit;
int t[N], p[N];

void solve(int depth, int cost) {
	if (depth == n) {
		if (max_benefit < cost) max_benefit = cost;
		return;
	}

	if (depth + t[depth] <= n) solve(depth + t[depth], cost + p[depth]);
	solve(depth + 1, cost);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}
	solve(0, 0);
	cout << max_benefit;

	return 0;
}