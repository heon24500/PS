#include <iostream>
#include <stack>
using namespace std;

struct Node {
	int y, x, d;
};

const int N = 13, K = 11;
int n, k, ans;
int mat[N][N];
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };
stack<int> s[N][N];
Node node[K];

bool isPossible(int y, int x) {
	if (y < 1 || y > n || x < 1 || x > n || mat[y][x] == 2) return false;
	return true;
}

int changeDir(int d) {
	if (d == 1) return 2;
	if (d == 2) return 1;
	if (d == 3) return 4;
	if (d == 4) return 3;
}

void solve() {
	for (ans = 1; ans <= 1000; ans++) {
		for (int i = 1; i <= k; i++) {
			int y = node[i].y;
			int x = node[i].x;
			int d = node[i].d;

			int ty = y + dy[d];
			int tx = x + dx[d];
			if (!isPossible(ty, tx)) {
				d = changeDir(d);
				ty = y + dy[d];
				tx = x + dx[d];
				node[i].d = d;
				if (!isPossible(ty, tx)) continue;
			}

			if (mat[ty][tx] == 0) {
				stack<int> temp;
				while (s[y][x].top() != i) {
					int num = s[y][x].top();
					temp.push(num);
					s[y][x].pop();
					node[num].y = ty;
					node[num].x = tx;
				}
				s[y][x].pop();
				s[ty][tx].push(i);
				node[i].y = ty;
				node[i].x = tx;
				while (!temp.empty()) {
					s[ty][tx].push(temp.top());
					temp.pop();
				}
			}
			if (mat[ty][tx] == 1) {
				while (s[y][x].top() != i) {
					int num = s[y][x].top();
					s[ty][tx].push(num);
					s[y][x].pop();
					node[num].y = ty;
					node[num].x = tx;
				}
				s[y][x].pop();
				s[ty][tx].push(i);
				node[i].y = ty;
				node[i].x = tx;
			}

			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (s[i][j].size() >= 4) return;
				}
			}
		}
	}
	ans = -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 1; i <= k; i++) {
		int y, x, d;
		cin >> y >> x >> d;
		node[i] = { y, x, d };
		s[y][x].push(i);
	}

	solve();
	cout << ans;

	return 0;
}