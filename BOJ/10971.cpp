#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int w[11][11];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		d[i] = i;
	}

	int ret = 1e9;
	while (true) {
		bool flag = true;
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			if (w[d[i]][d[i + 1]]) sum += w[d[i]][d[i + 1]];
			else flag = false;
		}

		if (flag && w[d[n - 1]][d[0]]) {
			sum += w[d[n - 1]][d[0]];
			ret = min(ret, sum);
		}

		if (!next_permutation(d.begin(), d.end())) break;
	}
	cout << ret;

	return 0;
}