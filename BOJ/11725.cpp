#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 100001;
int n;
int parent[N];
bool visited[N];
vector<int> adj[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto u : adj[now]) {
			if (visited[u]) continue;
			parent[u] = now;
			q.push(u);
			visited[u] = true;
		}
	}

	for (int i = 2; i <= n; i++) cout << parent[i] << "\n";

	return 0;
}