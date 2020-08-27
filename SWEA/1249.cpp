/* 1249. [S/W 문제해결 응용] 4일차 - 보급로 */
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int mat[100][100];
int dist[100][100];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
priority_queue<pair<int, pii>> pq;

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char ch;
				cin >> ch;
				mat[i][j] = ch - '0';
			}
		}
		pii s = make_pair(0, 0);
		pii g = make_pair(n - 1, n - 1);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = 1e9;
			}
		}

		dist[0][0] = 0;
		pq.push(make_pair(0, s));

		while (!pq.empty()) {
			int cost = -pq.top().first;
			pii here = pq.top().second;
			pq.pop();

			int y = here.first;
			int x = here.second;
			if (dist[y][x] < cost) continue;

			for (int i = 0; i < 4; i++) {
				int ty = y + dy[i];
				int tx = x + dx[i];
				pii there = make_pair(ty, tx);
				int nextDist = cost + mat[y][x];

				if (ty < 0 || ty >= n || tx < 0 || tx >= n) continue;
				if (dist[ty][tx] > nextDist) {
					dist[ty][tx] = nextDist;
					pq.push(make_pair(-nextDist, there));
				}
			}
		}

		cout << "#" << tc << " " << dist[g.first][g.second] << '\n';
	}

	return 0;
}