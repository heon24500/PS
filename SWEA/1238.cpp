/* 1238. [S/W 문제해결 기본] 10일차 - Contact */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 101;
vector<int> v[N];
queue<int> q;
bool visited[N];
int dist[N];

void Init() {
	for (int i = 0; i < N; i++) {
		dist[i] = 0;
		visited[i] = false;
		v[i].clear();
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 1; t <= 10; t++) {
		int len, src;
		cin >> len >> src;
		for (int i = 0; i < len / 2; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
		}


		// BFS
		q.push(src);
		visited[src] = true;
		dist[src] = 0;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (auto u : v[now]) {
				if (visited[u]) continue;
				q.push(u);
				visited[u] = true;
				dist[u] = dist[now] + 1;
			}
		}

		int ret = 0;
		for (int i = 1; i < N; i++) {
			if (dist[ret] <= dist[i]) ret = i;
		}

		cout << "#" << t << " " << ret << '\n';
		Init();
	}

	return 0;
}