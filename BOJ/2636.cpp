/* 2636. ДЎБо */
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

const int N = 105;
int n, m, times, cnt;
int mat[N][N];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
bool visited[N][N];
bool checked[N][N];
vector<pii> v;

void dfs(int y, int x) {
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];

		if (ty >= 0 && ty < n && tx >= 0 && tx < m) {
			if (mat[ty][tx] == 1 && !checked[ty][tx]) {
				v.push_back(make_pair(ty, tx));
				checked[ty][tx] = true;
			}
			if (mat[ty][tx] == 0 && !visited[ty][tx]) dfs(ty, tx);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	int bf_cnt = 0;
	while (true) {
		bf_cnt = cnt;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 1) cnt++;
			}
		}

		if (cnt == 0) break;
		else times++;

		dfs(0, 0);

		for (int i = 0; i < v.size(); i++) {
			mat[v[i].first][v[i].second] = 0;
		}
		v.clear();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = false;
				checked[i][j] = false;
			}
		}
	}

	cout << times << '\n' << bf_cnt;

	return 0;
}