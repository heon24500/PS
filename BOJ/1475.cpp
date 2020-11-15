#include <iostream>
using namespace std;

int cnt[10];

int main() {
	int n;
	cin >> n;
	if (n == 0) cnt[0]++;
	while (n > 0) {
		int num = n % 10;
		if (num == 6 || num == 9) {
			if (cnt[6] > cnt[9]) cnt[9]++;
			else cnt[6]++;
		}
		else cnt[num]++;
		n /= 10;
	}

	int ans = 0;
	for (int i = 0; i < 10; i++) ans = max(ans, cnt[i]);
	cout << ans;

	return 0;
}