#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		int ans = x;
		int lcm = m * n / gcd(m, n);
		bool isFinish = false;
		while (ans <= lcm) {
			if ((ans - 1) % n + 1 == y) {
				isFinish = true;
				break;
			}
			ans += m;
		}
		if (isFinish) cout << ans << '\n';
		else cout << "-1\n";
	}

	return 0;
}