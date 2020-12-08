#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int l, n;
	cin >> l >> n;

	int max_expect = 0, max_real = 0;
	int max_len = 0, max_cnt = 0;
	int cnt[1001] = { 0 };

	for (int i = 1; i <= n; i++) {
		int p, k;
		cin >> p >> k;
		int len = k - p + 1;
		if (max_len < len) {
			max_len = len;
			max_expect = i;
		}

		int now_cnt = 0;
		for (int j = p; j <= k; j++) {
			if (cnt[j]) continue;
			cnt[j] = i;
			now_cnt++;
		}
		if (max_cnt < now_cnt) {
			max_cnt = now_cnt;
			max_real = i;
		}
	}

	cout << max_expect << '\n' << max_real << '\n';

	return 0;
}