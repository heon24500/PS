#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, string> pis;

bool comp(pis a, pis b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pis> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].second >> v[i].first;
	sort(v.begin(), v.end(), comp);
	cout << v[0].second;

	return 0;
}