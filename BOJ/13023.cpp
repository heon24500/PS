#include <iostream>
#include <vector>
using namespace std;

bool visited[2001];
bool is_found = false;
vector<int> adj[2001];

void dfs(int n, int cnt) {
	if (cnt == 4) {
		is_found = true;
		return;
	}

	visited[n] = true;
	for (auto u : adj[n]) {
		if (visited[u]) continue;
		dfs(u, cnt + 1);
		if (is_found) return;
	}
	visited[n] = false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < n; i++) {
		if (is_found) break;
		dfs(i, 0);
	}

	if (is_found) cout << "1";
	else cout << "0";

	return 0;
}