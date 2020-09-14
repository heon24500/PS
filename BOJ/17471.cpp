#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 11;
int n, cnt, ret = 1e9;
int pop[N];
bool visited[N];
vector<int> adj[N];

bool bfs(vector<int> v) {
	vector<bool> check(N);
	queue<int> q;
	int s = v[0];
	q.push(s);
	check[s] = true;

	cnt = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cnt += pop[now];

		for (auto u : adj[now]) {
			bool flag = true;
			for (int i = 0; i < v.size(); i++) {
				if (check[u]) continue;
				if (v[i] == u) {
					q.push(u);
					check[u] = true;
				}
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (!check[v[i]]) return false;
	}
	return true;
}

void solve(int depth, int idx, int len) {
	if (depth == n) {
		if (len == 0 || len == n) return;
		vector<int> v1, v2;
		for (int i = 1; i <= n; i++) {
			if (visited[i]) v1.push_back(i);
			else v2.push_back(i);
		}
		if (!bfs(v1)) return;
		int cnt_temp = cnt;
		if (!bfs(v2)) return;
		int diff = abs(cnt_temp - cnt);
		if (ret > diff) ret = diff;

		return;
	}

	for (int i = idx + 1; i <= n; i++) {
		visited[i] = true;
		solve(depth + 1, i, len + 1);
		visited[i] = false;
		solve(depth + 1, i, len);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> pop[i];
	}
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int u;
			cin >> u;
			adj[i].push_back(u);
		}
	}

	solve(0, 0, 0);
	if (ret == 1e9) ret = -1;
	cout << ret;

	return 0;
}