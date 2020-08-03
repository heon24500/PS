/* 1226. [S/W 문제해결 기본] 7일차 - 미로1 */
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int N = 16;
queue<pii> q;
char mat[N][N];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
pii src, dest;
bool visited[N][N];

bool isPossible(int y, int x) {
	if (y >= 0 && y < N && x >= 0 && x < N && mat[y][x] != '1' && !visited[y][x]) return true;
	else return false;
}

void Init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}

	while (!q.empty()) {
		q.pop();
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 0; t < 10; t++) {
		int t_num;
		cin >> t_num;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> mat[i][j];
				if (mat[i][j] == '2') src = make_pair(i, j);
				if (mat[i][j] == '3') dest = make_pair(i, j);
			}
		}

		// BFS
		q.push(src);
		visited[src.first][src.second] = true;

		while (!q.empty()) {
			pii now = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ty = now.first + dy[i];
				int tx = now.second + dx[i];
				
				if (!isPossible(ty, tx)) continue;
				q.push(make_pair(ty, tx));
				visited[ty][tx] = true;
			}
		}

		cout << "#" << t_num << " ";
		if (visited[dest.first][dest.second]) cout << "1\n";
		else cout << "0\n";

		Init();
	}

	return 0;
}