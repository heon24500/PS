#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

#define N 20

vector<pii> v[N];
int t[N];
int p[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	v[1].push_back({ 0, 0 });
	v[1].push_back({ t[1], p[1] });

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < v[i - 1].size(); j++) {
			pii before = v[i - 1][j];
			int day = before.first - 1;
			int cost = before.second;

			if (day > 0) v[i].push_back({ day, cost });
			else {
				v[i].push_back({ 0, cost });
				v[i].push_back({ t[i], cost + p[i] });
			}
		}
	}

	int max = 0;
	for (int i = 0; i < v[n].size(); i++) {
		if (v[n][i].first > 1) continue;
		if (max < v[n][i].second) max = v[n][i].second;
	}

	cout << max;

	return 0;
}