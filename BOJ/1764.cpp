#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> v;

	for (int i = 0; i < n + m; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	int ret = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] == v[i + 1]) ret++;
	}
	cout << ret << "\n";
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] == v[i + 1]) cout << v[i] << "\n";
	}

	return 0;
}