/* 1221. [S/W 문제해결 기본] 5일차 - GNS */
#include <iostream>
using namespace std;

string nums[10] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		char temp;
		int test_case, n;
		cin >> temp >> test_case >> n;

		int cnt[10] = { 0 };
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			int num = 0;
			while (nums[num] != str) {
				num++;
			}
			cnt[num]++;
		}

		cout << "#" << tc << '\n';
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < cnt[i]; j++) {
				cout << nums[i] << " ";
			}
		}
		cout << '\n';
	}

	return 0;
}