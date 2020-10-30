#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v;
	for (int i = 0; i < n + m; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (auto u : v) printf("%d ", u);

	return 0;
}