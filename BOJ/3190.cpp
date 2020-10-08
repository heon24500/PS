#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int N = 101;
int n, k, l, d = 0;
int mat[N][N];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
queue<pii> moves;
queue<pii> snake;

bool isWall(int y, int x) {
	if (y <= 0 || y > n || x <= 0 || x > n) return true;
	return false;
}

void removeTail() {
	pii tail = snake.front();
	mat[tail.first][tail.second] = 0;
	snake.pop();
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;
		mat[y][x] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		if (c == 'L') moves.push({ x, -1 });
		else moves.push({ x, 1 });
	}

	int y = 1, x = 1;
	mat[y][x] = 2;
	snake.push({ y, x });

	int times = 0;
	pii now = moves.front();
	while (true) {
		times++;

		if (!moves.empty() && times > now.first) {
			d += now.second;
			if (d < 0) d = 3;
			if (d > 3) d = 0;
			moves.pop();
			if (!moves.empty()) now = moves.front();
		}

		int ty = y + dy[d];
		int tx = x + dx[d];
		if (isWall(ty, tx)) break;

		if (mat[ty][tx] == 2) break;
		else {
			if (mat[ty][tx] != 1) removeTail();
			mat[ty][tx] = 2;
		}
		snake.push({ ty, tx });

		y = ty;
		x = tx;
	}
	cout << times;

	return 0;
}