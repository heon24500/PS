#include <iostream>
#include <vector>
using namespace std;

typedef pair<long, pair<int, pair<int, pair<int, int> > > > plpipipii;

#define N 15

int a[N];
int calc[4];  // 0 : +,  1 : -,  2 : *,  3 : /
vector<plpipipii> v[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> calc[i];
	}

	v[0].push_back({ a[0], {calc[0], {calc[1], {calc[2], calc[3]}}} });
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < v[i - 1].size(); j++) {
			int this_calc[4];
			long before = v[i - 1][j].first;
			this_calc[0] = v[i - 1][j].second.first;
			this_calc[1] = v[i - 1][j].second.second.first;
			this_calc[2] = v[i - 1][j].second.second.second.first;
			this_calc[3] = v[i - 1][j].second.second.second.second;

			if (this_calc[0] != 0) {
				long result = before + a[i];
				v[i].push_back({ result, {this_calc[0] - 1, {this_calc[1], {this_calc[2], this_calc[3]}}} });
			}
			if (this_calc[1] != 0) {
				long result = before - a[i];
				v[i].push_back({ result, {this_calc[0], {this_calc[1] - 1, {this_calc[2], this_calc[3]}}} });
			}
			if (this_calc[2] != 0) {
				long result = before * a[i];
				v[i].push_back({ result, {this_calc[0], {this_calc[1], {this_calc[2] - 1, this_calc[3]}}} });
			}
			if (this_calc[3] != 0) {
				long result = before / a[i];
				v[i].push_back({ result, {this_calc[0], {this_calc[1], {this_calc[2], this_calc[3] - 1}}} });
			}
		}
	}

	long min = 1000000000, max = -1000000000;
	for (int i = 0; i < v[n - 1].size(); i++) {
		long result = v[n - 1][i].first;
		if (min > result) min = result;
		if (max < result) max = result;
	}

	cout << max << "\n" << min;

	return 0;
}