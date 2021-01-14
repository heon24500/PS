#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int cnt[2005] = { 0 };
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (cnt[num + 1000]) continue;
		cnt[num + 1000] = 1;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	for (int i : v) cout << i << " ";

	return 0;
}