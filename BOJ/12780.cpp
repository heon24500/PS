#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string h, n;
	cin >> h >> n;

	int idx = -1, ans = 0;
	while (true) {
		idx = h.find(n, idx + 1);
		if (idx == string::npos) break;
		ans++;
	}
	cout << ans;

	return 0;
}