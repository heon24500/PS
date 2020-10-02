#include <iostream>
using namespace std;

const int N = 100;
int cnt[N][150];
int n;
string words[N];

bool isSim(int idx) {
	int sum = 0;
	int len1 = words[0].length();
	int len2 = words[idx].length();
	for (int i = 'A'; i <= 'Z'; i++) {
		sum += abs(cnt[0][i] - cnt[idx][i]);
		if (len1 != len2 && sum > 1) return false;
		if (len1 == len2 && sum > 2) return false;
	}
	return true;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> words[i];
		int len = words[i].length();
		for (int j = 0; j < len; j++) {
			cnt[i][words[i][j]]++;
		}
	}

	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (isSim(i)) ans++;
	}
	cout << ans;

	return 0;
}