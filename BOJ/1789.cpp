#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll s, sum = 0, cnt = 2;
	cin >> s;

	while (true) {
		sum = (cnt * (cnt + 1)) / 2 - 1;
		if (sum >= s) break;
		cnt++;
	}

	cout << cnt - 1;

	return 0;
}