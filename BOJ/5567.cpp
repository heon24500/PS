#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 501;
int n, m, cnt = -1;
int dist[N];
bool visited[N];
vector<int> friends[N];

void solve() {
	queue<int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cnt++;

		if (dist[now] >= 2) continue;

		for (auto u : friends[now]) {
			if (visited[u]) continue;
			q.push(u);
			visited[u] = true;
			dist[u] = dist[now] + 1;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	solve();
	cout << cnt;

	return 0;
}