#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculate(vector<int> a) {
	int ret = 0;
	for (int i = 0; i <= a.size() - 2; i++) {
		ret += abs(a[i] - a[i + 1]);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	int ret = 0;
	while (true) {
		int result = calculate(a);
		ret = max(ret, result);
		if (!next_permutation(a.begin(), a.end())) break;
	}
	cout << ret;

	return 0;
}