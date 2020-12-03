#include <iostream>
#include <queue>
using namespace std;

typedef pair<pair<int, int>, int> piipi;

const int W = 12, H = 15;
int t, n, w, h, ans = 1e9;
int mat[H][W];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void backup(int mat_bak[H][W], bool flag) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (flag) mat_bak[i][j] = mat[i][j];
			else mat[i][j] = mat_bak[i][j];
		}
	}
}

bool isPossible(int y, int x) {
	if (y < 0 || y >= h || x < 0 || x >= w || mat[y][x] == 0) return false;
	return true;
}

bool destroyBlks(int idx) {
	queue<piipi> q;
	bool visited[H][W] = { 0 };

	bool ret = false;
	for (int y = 0; y < h; y++) {
		if (mat[y][idx] == 0) continue;
		q.push({ {y, idx}, mat[y][idx] });
		visited[y][idx] = true;
		ret = true;
		break;
	}

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int num = q.front().second;
		q.pop();

		mat[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < num; j++) {
				int ty = y + dy[i] * j;
				int tx = x + dx[i] * j;
				if (!isPossible(ty, tx) || visited[ty][tx]) continue;
				q.push({ {ty, tx}, mat[ty][tx] });
				visited[ty][tx] = true;
			}
		}
	}

	return ret;
}

void moveBlks() {
	for (int y = h - 1; y >= 0; y--) {
		for (int x = 0; x < w; x++) {
			if (mat[y][x] == 0) continue;
			int idx = y;
			while (idx + 1 < h && mat[idx + 1][x] == 0) idx++;
			swap(mat[y][x], mat[idx][x]);
		}
	}
}

void solve(int depth) {
	if (depth == n) {
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (mat[i][j] > 0) cnt++;
			}
		}
		ans = min(ans, cnt);
		return;
	}

	int mat_bak[H][W];
	backup(mat_bak, true);

	bool is_finish = true;
	for (int i = 0; i < w; i++) {
		if (!destroyBlks(i)) continue;
		is_finish = false;
		moveBlks();
		solve(depth + 1);
		backup(mat_bak, false);
	}
	if (is_finish) solve(n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> mat[i][j];
			}
		}

		ans = 1e9;
		solve(0);
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}