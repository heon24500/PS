/* 1949. [모의 SW 역량테스트] 등산로 조성 */
#include <iostream>
#include <vector>
using namespace std;

const int N = 8;
int n, k, max_len;
int mat[N][N];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
bool visited[N][N];

bool isPossible(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= n || visited[y][x]) return false;
	return true;
}

void solve(int y, int x, int len, int cnt) {
	if (max_len < len) max_len = len;

	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];
		if (!isPossible(ty, tx)) continue;
		if (mat[ty][tx] < mat[y][x]) {
			visited[ty][tx] = true;
			solve(ty, tx, len + 1, cnt);
			visited[ty][tx] = false;
		}
		else if (cnt == 0 && mat[ty][tx] - k < mat[y][x]) {
			int temp = mat[ty][tx];
			mat[ty][tx] = mat[y][x] - 1;
			visited[ty][tx] = true;
			solve(ty, tx, len + 1, cnt + 1);
			mat[ty][tx] = temp;
			visited[ty][tx] = false;
		}
	}
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}

	max_len = 0;
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> k;
		vector<pair<int, int> > max_heights;
		int max_height = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
				if (max_height < mat[i][j]) {
					max_height = mat[i][j];
					max_heights.clear();
					max_heights.push_back(make_pair(i, j));
				}
				else if (max_height == mat[i][j]) max_heights.push_back(make_pair(i, j));
			}
		}

		for (int i = 0; i < max_heights.size(); i++) {
			int y = max_heights[i].first;
			int x = max_heights[i].second;
			visited[y][x] = true;
			solve(y, x, 1, 0);
			visited[y][x] = false;
		}

		cout << "#" << tc << " " << max_len << '\n';
		init();
	}

	return 0;
}