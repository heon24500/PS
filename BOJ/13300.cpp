#include <iostream>
using namespace std;

int main() {
	int st[2][7] = { 0 };
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int s, y;
		cin >> s >> y;
		st[s][y]++;
	}

	int ret = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 7; j++) {
			if (st[i][j] == 0) continue;
			ret += st[i][j] / k;
			if (st[i][j] % k != 0) ret++;
		}
	}
	cout << ret;

	return 0;
}