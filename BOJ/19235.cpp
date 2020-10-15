#include <iostream>
using namespace std;

int mat[10][10];
int block = 1, ans;

// �Է� �޴� �Լ�
void push(int t, int x, int y) {
	int tx = 0, ty = 0;
	if (t == 1) {
		while (tx < 9 && mat[tx + 1][y] == 0) tx++;
		while (ty < 9 && mat[x][ty + 1] == 0) ty++;
		mat[tx][y] = mat[x][ty] = block;
	}
	if (t == 2) {
		while (tx < 9 && mat[tx + 1][y] == 0 && mat[tx + 1][y + 1] == 0) tx++;
		while (ty < 8 && mat[x][ty + 1] == 0 && mat[x][ty + 2] == 0) ty++;
		mat[tx][y] = mat[tx][y + 1] = mat[x][ty] = mat[x][ty + 1] = block;
	}
	if (t == 3) {
		while (tx < 8 && mat[tx + 1][y] == 0 && mat[tx + 2][y] == 0) tx++;
		while (ty < 9 && mat[x][ty + 1] == 0 && mat[x + 1][ty + 1] == 0) ty++;
		mat[tx][y] = mat[tx + 1][y] = mat[x][ty] = mat[x + 1][ty] = block;
	}
	block++;
}

// ���� �����ϴ� �Լ�
bool removeLine() {
	bool ret = false;
	for (int x = 6; x < 10; x++) {
		bool isLine = true;
		for (int y = 0; y < 4; y++) {
			if (mat[x][y] == 0) {
				isLine = false;
				break;
			}
		}
		if (isLine) {
			for (int y = 0; y < 4; y++) mat[x][y] = 0;
			ans++;
			ret = true;
		}
	}

	for (int y = 6; y < 10; y++) {
		bool isLine = true;
		for (int x = 0; x < 4; x++) {
			if (mat[x][y] == 0) {
				isLine = false;
				break;
			}
		}
		if (isLine) {
			for (int x = 0; x < 4; x++) mat[x][y] = 0;
			ans++;
			ret = true;
		}
	}

	return ret;
}

// ����� �����ϴ� �Լ�
bool removeSpecial() {
	bool ret = false;
	int cnt = 0;
	for (int x = 4; x < 6; x++) {
		bool isSpecial = false;
		for (int y = 0; y < 4; y++) {
			if (mat[x][y] != 0) {
				isSpecial = true;
				break;
			}
		}
		if (isSpecial) {
			cnt++;
			ret = true;
		}
	}
	for (int x = 9; x > 9 - cnt; x--) {
		for (int y = 0; y < 4; y++) mat[x][y] = 0;
	}

	cnt = 0;
	for (int y = 4; y < 6; y++) {
		bool isSpecial = false;
		for (int x = 0; x < 4; x++) {
			if (mat[x][y] != 0) {
				isSpecial = true;
				break;
			}
		}
		if (isSpecial) {
			cnt++;
			ret = true;
		}
	}
	for (int y = 9; y > 9 - cnt; y--) {
		for (int x = 0; x < 4; x++) mat[x][y] = 0;
	}

	return ret;
}

// ��ü �̵��ϴ� �Լ�
void move() {
	for (int x = 8; x > 3; x--) {
		for (int y = 0; y < 4; y++) {
			if (y > 0 && mat[x][y] == mat[x][y - 1]) continue;
			if (x < 9 && mat[x][y] == mat[x + 1][y]) continue;

			int idx = x;
			if (y < 3 && mat[x][y] == mat[x][y + 1]) {
				while (idx < 9 && mat[idx + 1][y] == 0 && mat[idx + 1][y + 1] == 0) idx++;
				mat[idx][y] = mat[idx][y + 1] = mat[x][y];
				if (idx != x) mat[x][y] = mat[x][y + 1] = 0;
			}
			else if (mat[x][y] == mat[x - 1][y]) {
				while (idx < 9 && mat[idx + 1][y] == 0) idx++;
				mat[idx][y] = mat[idx - 1][y] = mat[x][y];
				if (idx >= x + 2) mat[x][y] = mat[x - 1][y] = 0;
				if (idx == x + 1) mat[x - 1][y] = 0;
			}
			else {
				while (idx < 9 && mat[idx + 1][y] == 0) idx++;
				mat[idx][y] = mat[x][y];
				if (idx != x) mat[x][y] = 0;
			}
		}
	}

	for (int y = 8; y > 3; y--) {
		for (int x = 0; x < 4; x++) {
			if (x > 0 && mat[x][y] == mat[x - 1][y]) continue;
			if (y < 9 && mat[x][y] == mat[x][y + 1]) continue;

			int idx = y;
			if (x < 3 && mat[x][y] == mat[x + 1][y]) {
				while (idx < 9 && mat[x][idx + 1] == 0 && mat[x + 1][idx + 1] == 0) idx++;
				mat[x][idx] = mat[x + 1][idx] = mat[x][y];
				if (idx != y) mat[x][y] = mat[x + 1][y] = 0;
			}
			else if (mat[x][y] == mat[x][y - 1]) {
				while (idx < 9 && mat[x][idx + 1] == 0) idx++;
				mat[x][idx] = mat[x][idx - 1] = mat[x][y];
				if (idx >= y + 2) mat[x][y] = mat[x][y - 1] = 0;
				if (idx == y + 1) mat[x][y - 1] = 0;
			}
			else {
				while (idx < 9 && mat[x][idx + 1] == 0) idx++;
				mat[x][idx] = mat[x][y];
				if (idx != y) mat[x][y] = 0;
			}
		}
	}
}

void solve(int t, int x, int y) {
	push(t, x, y);
	while (removeLine()) move();
	while (removeSpecial()) move();
	while (removeLine()) move();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int t, x, y;
		cin >> t >> x >> y;
		solve(t, x, y);
	}

	int cnt = 0;
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			if (x > 3 && y > 3) continue;
			if (mat[x][y] != 0) cnt++;
		}
	}
	cout << ans << '\n' << cnt;

	return 0;
}