#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int y;
	int x;
	int num;
	int dir;
};

const int N = 100;
int t, n, m, k;
int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };
queue<int> q[N][N];
vector<Node> v;

void moveNode() {
	for (int i = 0; i < k; i++) {
		int y = v[i].y;
		int x = v[i].x;
		int num = v[i].num;
		int dir = v[i].dir;
		if (num == 0) continue;

		int ty = y + dy[dir];
		int tx = x + dx[dir];
		if (ty == 0 || ty == n - 1 || tx == 0 || tx == n - 1) {
			v[i].num /= 2;
			if (dir == 1) v[i].dir = 2;
			else if (dir == 2) v[i].dir = 1;
			else if (dir == 3) v[i].dir = 4;
			else if (dir == 4) v[i].dir = 3;
		}

		q[ty][tx].push(i);
	}
}

void combNode() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (q[i][j].empty()) continue;
			if (q[i][j].size() == 1) {
				int idx = q[i][j].front();
				v[idx].y = i;
				v[idx].x = j;
				q[i][j].pop();
			}
			else {
				int idx = q[i][j].front();
				int y = v[idx].y;
				int x = v[idx].x;
				int max_num = v[idx].num;
				int sum = max_num;
				int max_idx = idx;
				v[idx].num = 0;
				v[idx].y = i;
				v[idx].x = j;
				q[i][j].pop();

				while (!q[i][j].empty()) {
					idx = q[i][j].front();
					q[i][j].pop();
					v[idx].y = i;
					v[idx].x = j;
					if (max_num < v[idx].num) {
						max_num = v[idx].num;
						max_idx = idx;
					}
					sum += v[idx].num;
					v[idx].num = 0;
				}

				v[max_idx].num = sum;
			}
		}
	}
}

int solve() {
	while (m--) {
		moveNode();
		combNode();
	}

	int ans = 0;
	for (int i = 0; i < k; i++) ans += v[i].num;
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m >> k;

		v.clear();
		for (int i = 0; i < k; i++) {
			int y, x, num, dir;
			cin >> y >> x >> num >> dir;
			Node node = { y, x, num, dir };
			v.push_back(node);
		}

		cout << "#" << tc << " " << solve() << '\n';
	}

	return 0;
}