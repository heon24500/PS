#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 101;
int n, m, kb, ans;
int dist[N][N];
vector<int> adj[N];

int bfs(int idx) {
	queue<int> q;
	bool visited[N] = { 0 };

	q.push(idx);
	visited[idx] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto u : adj[now]) {
			if (visited[u]) continue;
			q.push(u);
			visited[u] = true;
			dist[idx][u] = dist[idx][now] + 1;
		}
	}

	int ret = 0;
	for (int i = 1; i <= n; i++) ret += dist[idx][i];
	return ret;
}

void solve() {
	for (int i = 1; i <= n; i++) {
		int len = bfs(i);
		if (kb == 0) {
			kb = len;
			ans = i;
		}
		else {
			if (kb > len) {
				kb = len;
				ans = i;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	solve();
	cout << ans;

	return 0;
}