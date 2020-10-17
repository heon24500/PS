#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

struct Shark {
	int y, x, size = 2, eat;
};

const int N = 21;
int n, ans;
int mat[N][N];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
Shark shark;

bool isPossible(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= n || mat[y][x] > shark.size) return false;
	return true;
}

void solve() {
	while (true) {
		bool visited[N][N] = { 0 };
		int dist[N][N] = { 0 };
		queue<pii> q;
		q.push({ shark.y, shark.x });
		visited[shark.y][shark.x] = true;

		while (!q.empty()) {
			pii now = q.front();
			q.pop();
			int y = now.first;
			int x = now.second;
			for (int i = 0; i < 4; i++) {
				int ty = y + dy[i];
				int tx = x + dx[i];
				if (!isPossible(ty, tx) || visited[ty][tx]) continue;
				q.push({ ty, tx });
				visited[ty][tx] = true;
				dist[ty][tx] = dist[y][x] + 1;
			}
		}

		int min_dist = 1e9, dest_y = 0, dest_x = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] || mat[i][j] == 0 || mat[i][j] >= shark.size || min_dist <= dist[i][j]) continue;
				min_dist = dist[i][j];
				dest_y = i;
				dest_x = j;
			}
		}

		if (min_dist == 1e9) break;
		ans += min_dist;

		mat[dest_y][dest_x] = 9;
		mat[shark.y][shark.x] = 0;
		shark.y = dest_y;
		shark.x = dest_x;
		shark.eat++;
		if (shark.eat == shark.size) {
			shark.size++;
			shark.eat = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 9) {
				shark.y = i;
				shark.x = j;
			}
		}
	}

	solve();
	cout << ans;

	return 0;
}