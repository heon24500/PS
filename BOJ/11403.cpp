#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 105

vector<int> adj[N];
bool visited[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			if (num == 1) adj[i].push_back(j);
		}
	}

	for (int i = 0; i < n; i++) {
		queue<int> q;

		q.push(i);

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (auto u : adj[now]) {
				if (visited[u]) continue;

				q.push(u);
				visited[u] = true;
			}
		}

		for (int j = 0; j < n; j++) {
			if (visited[j]) cout << "1 ";
			else cout << "0 ";
			visited[j] = false;
		}
		cout << "\n";
	}

	return 0;
}