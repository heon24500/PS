/* 1259. [S/W 문제해결 응용] 7일차 - 금속막대 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int n;
vector<pii> ins, ret;
vector<bool> visited;

void init() {
	ins.clear();
	ret.clear();
	visited.clear();
}

void solve(vector<pii> v) {
	for (int i = 0; i < n; i++) {
		if (visited[i] || v[v.size() - 1].second != ins[i].first) continue;
		visited[i] = true;
		v.push_back(ins[i]);
		solve(v);
		v.pop_back();
	}

	if (v.size() > ret.size()) ret = v;
}


int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			ins.push_back(make_pair(a, b));
			visited.push_back(false);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[j] = false;
			}

			vector<pii> v;
			v.push_back(ins[i]);
			visited[i] = true;

			solve(v);
		}

		cout << "#" << tc << " ";
		for (int i = 0; i < ret.size(); i++) {
			cout << ret[i].first << " " << ret[i].second << " ";
		}
		cout << '\n';
		init();
	}

	return 0;
}