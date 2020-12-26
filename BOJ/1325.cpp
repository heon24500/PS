#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 10001;
int n, m;
vector<int> adj[N];

int bfs(int src) {
	int ret = 0;
	queue<int> q;
	bool visited[N] = { 0 };

	q.push(src);
	visited[src] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		ret++;

		for (auto next : adj[now]) {
			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}

	vector<int> ans;
	int max_cnt = 0;
	for (int i = 1; i <= n; i++) {
		int now = bfs(i);
		if (max_cnt < now) {
			ans.clear();
			ans.push_back(i);
			max_cnt = now;
		}
		else if (max_cnt == now) ans.push_back(i);
	}

	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

	return 0;
}