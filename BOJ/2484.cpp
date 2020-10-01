#include <iostream>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	while (n--) {
		int cnt[7] = { 0 };
		for (int i = 0; i < 4; i++) {
			int num;
			cin >> num;
			cnt[num]++;
		}

		int max_num = 1;
		for (int i = 2; i <= 6; i++) {
			if (cnt[max_num] <= cnt[i]) max_num = i;
		}

		int ret = 0;
		if (cnt[max_num] == 4) ret = 50000 + max_num * 5000;
		if (cnt[max_num] == 3) ret = 10000 + max_num * 1000;
		if (cnt[max_num] == 2) {
			bool flag = false;
			int i = 0;
			for (i = 1; i <= 6; i++) {
				if (i == max_num) continue;
				if (cnt[i] != 2) continue;
				flag = true;
				break;
			}
			if (flag) ret = 2000 + max_num * 500 + i * 500;
			else ret = 1000 + max_num * 100;
		}
		if (cnt[max_num] == 1) ret = max_num * 100;
		if (ans < ret) ans = ret;
	}
	cout << ans;

	return 0;
}