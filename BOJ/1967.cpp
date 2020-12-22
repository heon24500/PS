#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

const int N = 10001;
int n, ans_node, ans_dist;
bool visited[N];
vector<pii> adj[N];

void init() {
	for (int i = 1; i <= n; i++) visited[i] = false;
}

void dfs(int idx, int dist) {
	visited[idx] = true;

	if (ans_dist < dist) {
		ans_dist = dist;
		ans_node = idx;
	}

	for (auto u : adj[idx]) {
		if (visited[u.first]) continue;
		dfs(u.first, dist + u.second);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int src, dest, dist;
		cin >> src >> dest >> dist;
		adj[src].push_back({ dest, dist });
		adj[dest].push_back({ src, dist });
	}

	dfs(1, 0);
	init();
	dfs(ans_node, 0);
	cout << ans_dist;

	return 0;
}