#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 1001;
int t, n, k, w;
int d[N], tm[N], income[N];
vector<int> adj[N];

void init() {
	for (int i = 1; i <= n; i++) {
		tm[i] = 0;
		income[i] = 0;
		adj[i].clear();
	}
}

void solve() {
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (income[i] == 0) {
			q.push(i);
			tm[i] = d[i];
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : adj[now]) {
			tm[next] = max(tm[next], tm[now] + d[next]);
			income[next]--;
			if (income[next] == 0) q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> d[i];
		for (int i = 1; i <= k; i++) {
			int x, y;
			cin >> x >> y;
			income[y]++;
			adj[x].push_back(y);
		}
		cin >> w;
		solve();
		cout << tm[w] << '\n';
		init();
	}

	return 0;
}