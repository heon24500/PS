/* 7465. 창용 마을 무리의 개수 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 101;
vector<int> adj[N];
bool visited[N];

void init() {
	for (int i = 0; i < N; i++) {
		adj[i].clear();
		visited[i] = false;
	}
}

void bfs(int n) {
	queue<int> q;
	q.push(n);
	visited[n] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto u : adj[now]) {
			if (visited[u]) continue;
			q.push(u);
			visited[u] = true;
		}
	}
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (visited[i]) continue;
			bfs(i);
			cnt++;
		}

		cout << "#" << tc << " " << cnt << '\n';
		init();
	}

	return 0;
}