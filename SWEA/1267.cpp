/* 1267. [S/W 문제해결 응용] 10일차 - 작업순서 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int V = 1005;
vector<int> adj[V];
vector<int> in_adj[V];
queue<int> q;
bool visited[V];

bool CanSearch(int n) {
	if (visited[n]) return false;
	for (int i = 0; i < in_adj[n].size(); i++) {
		if (!visited[in_adj[n][i]]) return false;
	}
	return true;
}

void Init() {
	for (int i = 0; i < V; i++) {
		adj[i].clear();
		in_adj[i].clear();
		visited[i] = false;
	}
	while (!q.empty()) {
		q.pop();
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 0; t < 10; t++) {
		int v, e;
		cin >> v >> e;
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			in_adj[b].push_back(a);
		}

		cout << "#" << t + 1 << " ";
		for (int i = 1; i <= v; i++) {
			if (!CanSearch(i)) continue;

			q.push(i);
			visited[i] = true;

			while (!q.empty()) {
				int now = q.front();
				q.pop();

				cout << now << " ";

				for (auto u : adj[now]) {
					if (!CanSearch(u)) continue;
					q.push(u);
					visited[u] = true;
				}
			}
		}
		cout << '\n';
		Init();
	}

	return 0;
}