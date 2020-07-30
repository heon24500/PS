/* 7568. µ¢Ä¡ */
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
vector<pii> v;
vector<int> ret;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (v[i].first < v[j].first && v[i].second < v[j].second) cnt++;
		}
		ret.push_back(cnt + 1);
	}

	for (int i = 0; i < n; i++) {
		cout << ret[i] << ' ';
	}

	return 0;
}