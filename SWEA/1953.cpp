/* 1953. [모의 SW 역량테스트] 탈주범 검거 */
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int N = 50, M = 50;
int n, m, r, c, l;
int mat[N][M];
int dist[N][M];
int dy[4] = { -1, 1, 0, 0 };  // 순서대로 상하좌우
int dx[4] = { 0, 0, -1, 1 };
vector<pii> tunnel[8];
bool visited[N][M];

bool isPossible(int y, int x, int ty, int tx) {
	// 이미 방문하였거나 boundary를 벗어났거나 이동할 터널이 없는 경우 false
	if (visited[ty][tx] || ty < 0 || ty >= n || tx < 0 || tx >= m || mat[ty][tx] == 0) return false;
	
	// 터널이 서로 연결이 되지 않을 경우 false
	int d_y = ty - y;
	int d_x = tx - x;
	if (d_y == -1) {
		// 상으로 온 경우, 타입 3,4,7 연결 불가
		if (mat[ty][tx] == 3 || mat[ty][tx] == 4 || mat[ty][tx] == 7) return false;
	}
	else if (d_y == 1) {
		// 하로 온 경우, 타입 3,5,6 연결 불가
		if (mat[ty][tx] == 3 || mat[ty][tx] == 5 || mat[ty][tx] == 6) return false;
	}
	else {
		if (d_x == -1) {
			// 좌로 온 경우, 타입 2,6,7 연결 불가
			if (mat[ty][tx] == 2 || mat[ty][tx] == 6 || mat[ty][tx] == 7) return false;
		}
		else {
			// 우로 온 경우, 타입 2,4,5 연결 불가
			if (mat[ty][tx] == 2 || mat[ty][tx] == 4 || mat[ty][tx] == 5) return false;
		}
	}
	
	return true;
}

void setTunnel() {
	// 터널 타입 1 : 상하좌우로 이동가능
	for (int i = 0; i < 4; i++) {
		tunnel[1].push_back(make_pair(dy[i], dx[i]));
	}

	// 터널 타입 2 : 상하로 이동 가능
	tunnel[2].push_back(make_pair(dy[0], dx[0]));
	tunnel[2].push_back(make_pair(dy[1], dx[1]));

	// 터널 타입 3 : 좌우로 이동가능
	tunnel[3].push_back(make_pair(dy[2], dx[2]));
	tunnel[3].push_back(make_pair(dy[3], dx[3]));

	// 터널 타입 4 : 상우로 이동가능
	tunnel[4].push_back(make_pair(dy[0], dx[0]));
	tunnel[4].push_back(make_pair(dy[3], dx[3]));

	// 터널 타입 5 : 하우로 이동가능
	tunnel[5].push_back(make_pair(dy[1], dx[1]));
	tunnel[5].push_back(make_pair(dy[3], dx[3]));

	// 터널 타입 6 : 하좌로 이동가능
	tunnel[6].push_back(make_pair(dy[1], dx[1]));
	tunnel[6].push_back(make_pair(dy[2], dx[2]));

	// 터널 타입 7 : 상좌로 이동가능
	tunnel[7].push_back(make_pair(dy[0], dx[0]));
	tunnel[7].push_back(make_pair(dy[2], dx[2]));
}

void bfs(int sy, int sx) {
	queue<pii> q;
	q.push(make_pair(sy, sx));
	visited[sy][sx] = true;
	dist[sy][sx] = 1;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		int y = now.first;
		int x = now.second;
		int t = mat[y][x];
		if (dist[y][x] > l) return;

		for (int i = 0; i < tunnel[t].size(); i++) {
			int ty = y + tunnel[t][i].first;
			int tx = x + tunnel[t][i].second;
			if (!isPossible(y, x, ty, tx)) continue;
			q.push(make_pair(ty, tx));
			visited[ty][tx] = true;
			dist[ty][tx] = dist[y][x] + 1;
		}
	}
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	setTunnel();

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m >> r >> c >> l;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> mat[i][j];
			}
		}

		bfs(r, c);

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dist[i][j] >= 1 && dist[i][j] <= l) {
					cnt++;
				}
				dist[i][j] = 0;
				visited[i][j] = false;
			}
		}

		cout << "#" << tc << " " << cnt << '\n';
	}

	return 0;
}