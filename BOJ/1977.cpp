#include <iostream>
using namespace std;

int main() {
	int m, n, ans = 0;
	long long sum = 0;
	cin >> m >> n;
	for (int i = 0; i * i <= n; i++) {
		if (i * i < m) continue;
		if (ans == 0) ans = i * i;
		sum += i * i;
	}
	if (ans == 0) cout << "-1";
	else cout << sum << '\n' << ans;
}