#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int R = 251, C = 251;
int r, c, sheep, wolf;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
char mat[R][C];
bool visited[R][C];

bool isPossible(int y, int x) {
	if (y < 0 || y >= r || x < 0 || x >= c || visited[y][x] || mat[y][x] == '#') return false;
	return true;
}

void bfs(int y, int x) {
	queue<pii> q;
	q.push({ y, x });
	visited[y][x] = true;

	int now_sheep = 0, now_wolf = 0;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		if (mat[now.first][now.second] == 'v') now_wolf++;
		if (mat[now.first][now.second] == 'o') now_sheep++;

		for (int i = 0; i < 4; i++) {
			int ty = now.first + dy[i];
			int tx = now.second + dx[i];
			if (!isPossible(ty, tx)) continue;
			q.push({ ty, tx });
			visited[ty][tx] = true;
		}
	}

	if (now_sheep > now_wolf) sheep += now_sheep;
	else wolf += now_wolf;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (visited[i][j] || mat[i][j] == '.') continue;
			bfs(i, j);
		}
	}
	cout << sheep << " " << wolf;

	return 0;
}