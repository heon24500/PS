#include <iostream>
#include <vector>
using namespace std;

int cnt[150];
int n, mid;

bool isPossible() {
	bool flag = true;
	for (int i = 'A'; i <= 'Z'; i++) {
		if (cnt[i] == 0) continue;
		if (cnt[i] % 2 != 0) {
			mid = i;
			if (flag) flag = false;
			else return false;
		}
	}

	if (n % 2 == 0 && !flag) return false;
	return true;
}

void solve() {
	vector<char> ans(n);
	if (mid) ans[n / 2] = mid;
	int idx = 0;
	for (int i = 'A'; i <= 'Z'; i++) {
		if (cnt[i] == 0) continue;
		while (cnt[i] > 1) {
			ans[idx] = ans[n - 1 - idx] = i;
			cnt[i] -= 2;
			idx++;
		}
	}
	for (int i = 0; i < n; i++) cout << ans[i];
}

int main() {
	string str;
	cin >> str;
	n = str.length();
	for (int i = 0; i < n; i++) cnt[str[i]]++;
	if (isPossible()) solve();
	else cout << "I'm Sorry Hansoo\n";

	return 0;
}