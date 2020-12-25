#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		bool check[101] = { 0 };
		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= n; j += i) check[j] = !check[j];
		}
		for (int i = 1; i <= n; i++) {
			if (!check[i]) ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}