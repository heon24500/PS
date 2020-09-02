/* 1263. [S/W 문제해결 응용] 8일차 - 사람 네트워크2 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1001;
vector<int> adj[N];
int min_dist = 1e9;
int dist[N];
bool visited[N];

void init() {
	for (int i = 0; i < N; i++) {
		adj[i].clear();
	}
	min_dist = 1e9;
}

void bfs(int n) {
	queue<int> q;
	q.push(n);
	visited[n] = true;
	dist[n] = 0;
	int d = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto u : adj[now]) {
			if (visited[u]) continue;
			q.push(u);
			visited[u] = true;
			dist[u] = dist[now] + 1;
			d += dist[u];
		}
	}

	if (min_dist > d) min_dist = d;
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int num;
				cin >> num;
				if (num == 1) adj[i].push_back(j);
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				visited[j] = false;
			}

			bfs(i);
		}

		cout << "#" << tc << " " << min_dist << '\n';
		init();
	}

	return 0;
}