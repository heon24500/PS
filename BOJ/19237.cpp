#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

struct Shark {
	int y, x, d;
	bool alive;
};

const int N = 21, M = N * N;
int n, m, k, t;
int dir[M][5][4];
int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };
vector<pii> mat[N];
vector<int> q[N][N];
Shark shark[M];

bool isBoundary(int y, int x) {
	if (y < 1 || y > n || x < 1 || x > n) return true;
	return false;
}

void moveShark() {
	for (int i = 1; i <= m; i++) {
		if (!shark[i].alive) continue;
		int y = shark[i].y;
		int x = shark[i].x;
		int d = shark[i].d;

		bool flag = false;
		for (int j = 0; j < 4; j++) {
			int td = dir[i][d][j];
			int ty = y + dy[td];
			int tx = x + dx[td];
			if (isBoundary(ty, tx)) continue;
			if (mat[ty][tx].first != 0) continue;

			flag = true;
			shark[i].y = ty;
			shark[i].x = tx;
			shark[i].d = td;
			q[ty][tx].push_back(i);
			break;
		}

		if (!flag) {
			// 자신의 냄새가 있는 칸으로 이동
			for (int j = 0; j < 4; j++) {
				int td = dir[i][d][j];
				int ty = y + dy[td];
				int tx = x + dx[td];
				if (isBoundary(ty, tx) || mat[ty][tx].first != i) continue;

				shark[i].y = ty;
				shark[i].x = tx;
				shark[i].d = td;
				q[ty][tx].push_back(i);
				break;
			}
		}
	}
}

void removeSmell() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mat[i][j].first == 0) continue;
			mat[i][j].second--;
			if (mat[i][j].second == 0) mat[i][j].first = 0;
		}
	}
}

void eatShark() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (q[i][j].empty()) continue;
			int num = q[i][j][0];
			if (q[i][j].size() > 1) {
				int len = q[i][j].size();
				for (int l = 1; l < len; l++) {
					if (num > q[i][j][l]) {
						shark[num].alive = false;
						num = q[i][j][l];
					}
					else shark[q[i][j][l]].alive = false;
				}
			}
			mat[i][j].first = num;
			mat[i][j].second = k;
			q[i][j].clear();
		}
	}
}

bool isFinish() {
	for (int i = 2; i <= m; i++) {
		if (shark[i].alive) return false;
	}
	return true;
}

void solve() {
	t = 1;
	while (t <= 1000) {
		moveShark();  // 상어 이동
		removeSmell(); // 전체 냄새 시간 -1
		eatShark();  // 겹치는 경우 잡아먹기

		if (isFinish()) return;  // 끝났는지 확인
		t++;
	}
	t = -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		vector<pii> temp(N);
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			temp[j].first = num;
			if (num != 0) {
				temp[j].second = k;
				shark[num].y = i;
				shark[num].x = j;
				shark[num].alive = true;
			}
		}
		mat[i] = temp;
	}
	for (int i = 1; i <= m; i++) {
		cin >> shark[i].d;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int l = 0; l < 4; l++) {
				cin >> dir[i][j][l];
			}
		}
	}

	solve();
	cout << t;

	return 0;
}