#include <iostream>
using namespace std;

#define N 105
#define M 55

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, min_pack = 1000, min_each = 1000;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int pack, each;
		cin >> pack >> each;
		if (min_pack > pack) min_pack = pack;
		if (min_each > each) min_each = each;
	}

	int ret = 0;
	if (min_pack < min_each * 6) {
		int cnt = n / 6;
		n -= cnt * 6;
		if (min_pack < min_each * n) ret = min_pack * (cnt + 1);
		else ret = min_pack * cnt + min_each * n;
	}
	else ret = min_each * n;

	cout << ret;

	return 0;
}