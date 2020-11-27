#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> cnt(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		cnt[a]++;
		cnt[b]++;
	}

	for (int i = 1; i <= n; i++) cout << cnt[i] << '\n';

	return 0;
}