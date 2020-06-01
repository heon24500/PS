#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(y, x));
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		cout << v[i].second << " " << v[i].first << "\n";
	}

	return 0;
}