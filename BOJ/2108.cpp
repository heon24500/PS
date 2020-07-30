/* 2108. ≈Î∞Ë«– */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int cnt[8005];

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	double ret = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		ret += v[i];
		cnt[v[i] + 4000]++;
	}
	sort(v.begin(), v.end());

	ret /= n;
	cout << round(ret) << '\n';
	cout << v[n / 2] << '\n';

	int max_idx = 0;
	bool flag = true;
	for (int i = 1; i < 8005; i++) {
		if (cnt[max_idx] < cnt[i]) {
			max_idx = i;
			flag = true;
		}
		else if (cnt[max_idx] == cnt[i] && flag) {
			max_idx = i;
			flag = false;
		}
	}
	max_idx -= 4000;
	cout << max_idx << '\n';
	cout << abs(v[n - 1] - v[0]);

	return 0;
}