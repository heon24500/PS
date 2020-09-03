/* 1953. [���� SW �����׽�Ʈ] Ż�ֹ� �˰� */
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int N = 50, M = 50;
int n, m, r, c, l;
int mat[N][M];
int dist[N][M];
int dy[4] = { -1, 1, 0, 0 };  // ������� �����¿�
int dx[4] = { 0, 0, -1, 1 };
vector<pii> tunnel[8];
bool visited[N][M];

bool isPossible(int y, int x, int ty, int tx) {
	// �̹� �湮�Ͽ��ų� boundary�� ����ų� �̵��� �ͳ��� ���� ��� false
	if (visited[ty][tx] || ty < 0 || ty >= n || tx < 0 || tx >= m || mat[ty][tx] == 0) return false;
	
	// �ͳ��� ���� ������ ���� ���� ��� false
	int d_y = ty - y;
	int d_x = tx - x;
	if (d_y == -1) {
		// ������ �� ���, Ÿ�� 3,4,7 ���� �Ұ�
		if (mat[ty][tx] == 3 || mat[ty][tx] == 4 || mat[ty][tx] == 7) return false;
	}
	else if (d_y == 1) {
		// �Ϸ� �� ���, Ÿ�� 3,5,6 ���� �Ұ�
		if (mat[ty][tx] == 3 || mat[ty][tx] == 5 || mat[ty][tx] == 6) return false;
	}
	else {
		if (d_x == -1) {
			// �·� �� ���, Ÿ�� 2,6,7 ���� �Ұ�
			if (mat[ty][tx] == 2 || mat[ty][tx] == 6 || mat[ty][tx] == 7) return false;
		}
		else {
			// ��� �� ���, Ÿ�� 2,4,5 ���� �Ұ�
			if (mat[ty][tx] == 2 || mat[ty][tx] == 4 || mat[ty][tx] == 5) return false;
		}
	}
	
	return true;
}

void setTunnel() {
	// �ͳ� Ÿ�� 1 : �����¿�� �̵�����
	for (int i = 0; i < 4; i++) {
		tunnel[1].push_back(make_pair(dy[i], dx[i]));
	}

	// �ͳ� Ÿ�� 2 : ���Ϸ� �̵� ����
	tunnel[2].push_back(make_pair(dy[0], dx[0]));
	tunnel[2].push_back(make_pair(dy[1], dx[1]));

	// �ͳ� Ÿ�� 3 : �¿�� �̵�����
	tunnel[3].push_back(make_pair(dy[2], dx[2]));
	tunnel[3].push_back(make_pair(dy[3], dx[3]));

	// �ͳ� Ÿ�� 4 : ���� �̵�����
	tunnel[4].push_back(make_pair(dy[0], dx[0]));
	tunnel[4].push_back(make_pair(dy[3], dx[3]));

	// �ͳ� Ÿ�� 5 : �Ͽ�� �̵�����
	tunnel[5].push_back(make_pair(dy[1], dx[1]));
	tunnel[5].push_back(make_pair(dy[3], dx[3]));

	// �ͳ� Ÿ�� 6 : ���·� �̵�����
	tunnel[6].push_back(make_pair(dy[1], dx[1]));
	tunnel[6].push_back(make_pair(dy[2], dx[2]));

	// �ͳ� Ÿ�� 7 : ���·� �̵�����
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