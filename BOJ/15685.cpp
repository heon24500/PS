#include <iostream>
#include <vector>
using namespace std;

int n;
int mat[101][101];
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

bool isPossible(int y, int x) {
	if (y < 0 || y > 100 || x < 0 || x > 100) return false;
	return true;
}

void dragonCurve(int y, int x, int d, int g) {
	vector<int> dragon;
	dragon.push_back(d);
	for (int i = 0; i < g; i++) {
		int len = dragon.size();
		for (int j = len - 1; j >= 0; j--) {
			dragon.push_back((dragon[j] + 1) % 4);
		}
	}

	int ny = y;
	int nx = x;
	mat[ny][nx] = 1;
	int len = dragon.size();
	for (int i = 0; i < len; i++) {
		int ty = ny + dy[dragon[i]];
		int tx = nx + dx[dragon[i]];
		if (!isPossible(ty, tx)) continue;
		mat[ty][tx] = 1;
		ny = ty;
		nx = tx;
	}
}

int findRect() {
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (mat[i][j] == 1 && mat[i + 1][j] == 1 && mat[i][j + 1] == 1 && mat[i + 1][j + 1] == 1) cnt++;
		}
	}
	return cnt;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		dragonCurve(y, x, d, g);
	}
	cout << findRect();

	return 0;
}