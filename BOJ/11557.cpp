#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, string> pis;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pis> v(n);
		for (int i = 0; i < n; i++) cin >> v[i].second >> v[i].first;
		sort(v.begin(), v.end(), greater<pis>());
		cout << v[0].second << '\n';
	}

	return 0;
}