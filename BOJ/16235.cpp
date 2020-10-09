#include <iostream>
#include <queue>
using namespace std;

typedef pair<pair<int, int>, int> piipi;

const int N = 11;
int n, m, k, remain;
int a[N][N], mat[N][N];
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
deque<int> tree[N][N];
queue<piipi> deadTree;

void spring() {
	remain = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (tree[i][j].empty()) continue;
			remain++;

			int len = tree[i][j].size();
			while (len--) {
				int age = tree[i][j].front();
				tree[i][j].pop_front();
				if (age <= mat[i][j]) {
					mat[i][j] -= age;
					tree[i][j].push_back(age + 1);
				}
				else deadTree.push({ {i, j}, age });
			}
		}
	}
}

void summer() {
	while (!deadTree.empty()) {
		piipi now = deadTree.front();
		deadTree.pop();

		int y = now.first.first;
		int x = now.first.second;
		int age = now.second;
		mat[y][x] += (age / 2);
	}
}

void fall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (tree[i][j].empty()) continue;

			int len = tree[i][j].size();
			for (int idx = 0; idx < len; idx++) {
				if (tree[i][j][idx] % 5 != 0) continue;
				for (int idx2 = 0; idx2 < 8; idx2++) {
					int ty = i + dy[idx2];
					int tx = j + dx[idx2];
					if (ty <= 0 || ty > n || tx <= 0 || tx > n) continue;
					tree[ty][tx].push_front(1);
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			mat[i][j] += a[i][j];
		}
	}
}

int solve() {
	int year = 0;
	while (year++ < k) {
		spring();
		summer();
		fall();
		winter();
		if (remain == 0) return 0;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt += tree[i][j].size();
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			mat[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}

	cout << solve();

	return 0;
}