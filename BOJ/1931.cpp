#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 100005

vector<pair<int, int> > times;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		times.push_back(make_pair(s, e));
	}

	sort(times.begin(), times.end(), compare);
	int ret = 0, now = 0;
	for (int i = 0; i < n; i++) {
		if (now <= times[i].first) {
			now = times[i].second;
			ret++;
		}
	}
	cout << ret;

	return 0;
}