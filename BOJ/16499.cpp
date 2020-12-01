#include <iostream>
using namespace std;

const int N = 100;
int n, ans;
int cnt[N][150];

void comp(int now_cnt[150]) {
	for (int i = 0; i < ans; i++) {
		bool flag = true;
		for (int j = 'a'; j <= 'z'; j++) {
			if (now_cnt[j] != cnt[i][j]) flag = false;
			if (!flag) break;
		}
		if (flag) return;
	}
	for (int i = 'a'; i <= 'z'; i++) cnt[ans][i] = now_cnt[i];
	ans++;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		int now_cnt[150] = { 0 };
		for (int j = 0; str[j]; j++) now_cnt[str[j]]++;
		comp(now_cnt);
	}
	cout << ans;

	return 0;
}