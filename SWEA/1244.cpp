/* 1244. [S/W 문제해결 응용] 2일차 - 최대 상금 */
// 완탐으로 접근
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string num_str;
int ret, k;
int memo[11];

void init()
{
	num_str = "";
	ret = 0;
	k = 0;
	for (int i = 0; i < 11; i++) {
		memo[i] = false;
	}
}

void solve(int n)
{
	int num = stoi(num_str);
	if (memo[n] > num) return;
	if (n == k) {
		ret = max(ret, stoi(num_str));
		return;
	}
	memo[n] = num;

	for (int i = 0; i < num_str.length(); i++) {
		for (int j = i + 1; j < num_str.length(); j++) {
			swap(num_str[i], num_str[j]);
			solve(n + 1);
			swap(num_str[i], num_str[j]);
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> num_str >> k;
		solve(0);
		cout << "#" << tc << " " << ret << '\n';
		init();
	}

	return 0;
}