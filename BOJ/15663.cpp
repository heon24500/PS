#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool check[10];
int a[10], num[10];
vector<vector<int> > v;

void solve(int idx, int n, int m) {
	if (idx == m) {
		vector<int> temp;
		for (int i = 0; i < m; i++) {
			temp.push_back(num[a[i]]);
		}
		v.push_back(temp);
		return;
	}

	for (int i = 0; i < n; i++) {
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
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	solve(0, n, m);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto u : v) {
		for (int i = 0; i < m; i++) {
			cout << u[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}