#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, sum, ans = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	cin >> sum;

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (v[i] >= sum) break;
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i] + v[j] == sum) ans++;
			if (v[i] + v[j] >= sum) break;
		}
	}
	cout << ans;

	return 0;
}