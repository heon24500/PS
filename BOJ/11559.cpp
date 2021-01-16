#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

char mat[12][6];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

bool isPossible(int y, int x, int ch) {
	if (y < 0 || y >= 12 || x < 0 || x >= 6 || mat[y][x] != ch) return false;
	return true;
}

bool remove() {
	bool ret = false;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (mat[i][j] == '.') continue;
			char ch = mat[i][j];
			int cnt = 0;

			queue<pii> q, temp;
			bool visited[12][6] = { 0 };
			q.push({ i, j });
			temp.push({ i, j });
			visited[i][j] = true;

			while (!q.empty()) {
				pii now = q.front();
				q.pop();

				cnt++;

				for (int k = 0; k < 4; k++) {
					int ty = now.first + dy[k];
					int tx = now.second + dx[k];
					if (!isPossible(ty, tx, ch) || visited[ty][tx]) continue;
					q.push({ ty, tx });
					temp.push({ ty, tx });
					visited[ty][tx] = true;
				}
			}

			if (cnt >= 4) {
				while (!temp.empty()) {
					pii now = temp.front();
					temp.pop();
					mat[now.first][now.second] = '.';
				}
				ret = true;
			}
		}
	}

	return ret;
}

void move() {
	for (int i = 10; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (mat[i][j] == '.') continue;
			int idx = i;
			while (mat[idx + 1][j] == '.') idx++;
			swap(mat[idx][j], mat[i][j]);
		}
	}
}

int solve() {
	int ret = 0;

	while (true) {
		if (!remove()) break;
		move();
		ret++;
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> mat[i][j];
		}
	}

	cout << solve();

	return 0;
}