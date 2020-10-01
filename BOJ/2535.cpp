#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, pair<int, int> > pipii;

bool comp(pipii a, pipii b) {
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

int main() {
	int n;
	cin >> n;
	vector<pipii> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].second.first >> v[i].second.second >> v[i].first;
	}
	sort(v.begin(), v.end(), comp);

	int i = 2;
	cout << v[0].second.first << " " << v[0].second.second << '\n';
	cout << v[1].second.first << " " << v[1].second.second << '\n';
	if (v[0].second.first == v[1].second.first) {
		while (v[i].second.first == v[0].second.first) i++;
	}
	cout << v[i].second.first << " " << v[i].second.second << '\n';

	return 0;
}