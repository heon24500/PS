#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 100005

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		vector<pair<int, int> > v;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int p1, p2;
			cin >> p1 >> p2;
			v.push_back(make_pair(p1, p2));
		}

		sort(v.begin(), v.end(), compare);

		int ret = 1;
		bool flag = true;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (v[i].second > v[j].second) {
					flag = false;
					break;
				}
			}
			if (flag) ret++;
			else flag = true;
		}

		cout << ret << "\n";
	}

	return 0;
}