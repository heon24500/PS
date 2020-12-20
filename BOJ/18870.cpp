#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n), origin(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		origin[i] = v[i];
	}

	sort(v.begin(), v.end());

	int before = v[0], idx = 0;
	map<int, int> m;
	m[v[0]] = idx++;

	for (int i = 1; i < n; i++) {
		if (before == v[i]) continue;
		m[v[i]] = idx++;
		before = v[i];
	}

	for (int i = 0; i < n; i++) cout << m[origin[i]] << " ";

	return 0;
}