#include <iostream>
using namespace std;

char a[4] = "ABC";
char b[5] = "BABC";
char g[7] = "CCAABB";
int cnt[3];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char ch;
		cin >> ch;
		if (ch == a[i % 3]) cnt[0]++;
		if (ch == b[i % 4]) cnt[1]++;
		if (ch == g[i % 6]) cnt[2]++;
	}

	int max_cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (max_cnt < cnt[i]) max_cnt = cnt[i];
	}

	cout << max_cnt << '\n';
	if (max_cnt == cnt[0]) cout << "Adrian\n";
	if (max_cnt == cnt[1]) cout << "Bruno\n";
	if (max_cnt == cnt[2]) cout << "Goran\n";

	return 0;
}