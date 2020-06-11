#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int S = 1001;
int dist[S][S];
queue<pii> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	memset(dist, -1, sizeof(dist));

	q.push(make_pair(1, 0));
	dist[1][0] = 0;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		int s = now.first;
		int c = now.second;
		
		if (dist[s][s] == -1) {
			dist[s][s] = dist[s][c] + 1;
			q.push(make_pair(s, s));
		}
		if (s + c <= n && dist[s + c][c] == -1) {
			dist[s + c][c] = dist[s][c] + 1;
			q.push(make_pair(s + c, c));
		}
		if (s - 1 >= 0 && dist[s - 1][c] == -1) {
			dist[s - 1][c] = dist[s][c] + 1;
			q.push(make_pair(s - 1, c));
		}
	}

	int ret = -1;
	for (int i = 0; i <= n; i++) {
		if (dist[n][i] == -1) continue;
		if (ret == -1 || ret > dist[n][i]) ret = dist[n][i];
	}
	cout << ret;

	return 0;
}