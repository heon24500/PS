#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 105

vector<int> adj[N];
queue<int> q;
bool visited[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, e, ret = -1;
	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		ret++;

		for (auto u : adj[now]) {
			if (visited[u]) continue;

			visited[u] = true;
			q.push(u);
		}
	}

	cout << ret;

	return 0;
}