#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(int a, int b) {
	return a > b;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), comp);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int now = v[i] + i + 1;
		ans = max(ans, now);
	}
	cout << ans + 1;

	return 0;
}