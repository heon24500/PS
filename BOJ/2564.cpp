#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int n, m, nums;

int dist(pii src, pii dest) {
	if (src.second == dest.second) {
		return abs(src.first - dest.first);
	}
	else {
		int left = abs(src.second - dest.second) + src.first + dest.first;
		int right = abs(src.second - dest.second) + (n - src.first) + (n - dest.first);
		return min(left, right);
	}
}

int main() {
	cin >> n >> m >> nums;
	vector<pii> stores(nums);
	for (int i = 0; i < nums; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		if (n1 == 1) {
			stores[i].second = 0;
			stores[i].first = n2;
		}
		else if (n1 == 2) {
			stores[i].second = m;
			stores[i].first = n2;
		}
		else if (n1 == 3) {
			stores[i].first = 0;
			stores[i].second = n2;
		}
		else if (n1 == 4) {
			stores[i].first = n;
			stores[i].second = n2;
		}
	}
	pii start;
	int n1, n2;
	cin >> n1 >> n2;
	if (n1 == 1) {
		start.second = 0;
		start.first = n2;
	}
	else if (n1 == 2) {
		start.second = m;
		start.first = n2;
	}
	else if (n1 == 3) {
		start.first = 0;
		start.second = n2;
	}
	else if (n1 == 4) {
		start.first = n;
		start.second = n2;
	}

	int ret = 0;
	for (int i = 0; i < nums; i++) {
		ret += dist(start, stores[i]);
	}
	cout << ret;

	return 0;
}