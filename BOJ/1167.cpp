#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

const int V = 100001;
int v, ans_node, ans_dist;
bool visited[V];
vector<pii> adj[V];

void init() {
	for (int i = 1; i <= v; i++) visited[i] = false;
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

	cin >> v;
	for (int i = 0; i < v; i++) {
		int src, dest, dist;
		cin >> src;
		while (true) {
			cin >> dest;
			if (dest == -1) break;
			cin >> dist;
			adj[src].push_back({ dest, dist });
		}
	}

	dfs(1, 0);
	init();
	dfs(ans_node, 0);
	cout << ans_dist;

	return 0;
}