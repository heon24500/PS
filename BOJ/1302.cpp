#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, max_cnt = 0;
	cin >> n;

	map<string, int> m;
	string ans;
	while (n--) {
		string str;
		cin >> str;
		m[str]++;
		if (max_cnt < m[str]) {
			max_cnt = m[str];
			ans = str;
		}
		else if (max_cnt == m[str]) {
			ans = min(ans, str);
		}
	}
	cout << ans;

	return 0;
}