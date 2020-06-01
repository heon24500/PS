#include <iostream>
using namespace std;

int cost[6] = { 500, 100, 50, 10, 5, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, ret = 0;
	cin >> n;
	n = 1000 - n;
	for (int i = 0; i < 6; i++) {
		if (n == 0) break;
		if (n >= cost[i]) {
			int cnt = n / cost[i];
			n -= cnt * cost[i];
			ret += cnt;
		}
	}

	cout << ret;

	return 0;
}