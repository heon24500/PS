#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int x, y, now = 1, ret = 0;
		cin >> x >> y;
		int dist = y - x;
		while (dist > 0) {
			if (dist >= now * 2) {
				ret += 2;
				dist -= now * 2;
			}
			else {
				ret++;
				dist -= now;
			}
			now++;
		}

		cout << ret << '\n';
	}

	return 0;
}