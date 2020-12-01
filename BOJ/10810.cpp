#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	while (m--) {
		int i, j, k;
		cin >> i >> j >> k;
		for (int l = i; l <= j; l++) v[l] = k;
	}
	for (int i = 1; i <= n; i++) cout << v[i] << ' ';

	return 0;
}