#include <iostream>
using namespace std;

char Up[3][3], Down[3][3], Left[3][3], Right[3][3], Front[3][3], Back[3][3];

void init() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Up[i][j] = 'w';
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Down[i][j] = 'y';
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Front[i][j] = 'r';
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Back[i][j] = 'o';
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Left[i][j] = 'g';
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Right[i][j] = 'b';
		}
	}
}

void rotate(char u[3][3], char cir) {
	if (cir == '+') {
		// 윗면 회전(시계 방향)
		char temp = u[0][0];
		u[0][0] = u[2][0];
		u[2][0] = u[2][2];
		u[2][2] = u[0][2];
		u[0][2] = temp;

		temp = u[0][1];
		u[0][1] = u[1][0];
		u[1][0] = u[2][1];
		u[2][1] = u[1][2];
		u[1][2] = temp;
	}

	if (cir == '-') {
		// 윗면 회전(반시계 방향)
		char temp = u[0][0];
		u[0][0] = u[0][2];
		u[0][2] = u[2][2];
		u[2][2] = u[2][0];
		u[2][0] = temp;

		temp = u[0][1];
		u[0][1] = u[1][2];
		u[1][2] = u[2][1];
		u[2][1] = u[1][0];
		u[1][0] = temp;
	}
}

void rotateSide(char dir, char cir) {
	if ((dir == 'L' && cir == '+') || (dir == 'R' && cir == '-')) {
		int x = 0;
		if (dir == 'R') x = 2;
		for (int i = 0; i < 3; i++) {
			char temp = Front[i][x];
			Front[i][x] = Up[i][x];
			Up[i][x] = Back[i][x];
			Back[i][x] = Down[i][x];
			Down[i][x] = temp;
		}
	}
	if ((dir == 'L' && cir == '-') || (dir == 'R' && cir == '+')) {
		int x = 0;
		if (dir == 'R') x = 2;
		for (int i = 0; i < 3; i++) {
			char temp = Front[i][x];
			Front[i][x] = Down[i][x];
			Down[i][x] = Back[i][x];
			Back[i][x] = Up[i][x];
			Up[i][x] = temp;
		}
	}

	if ((dir == 'F' && cir == '+') || (dir == 'B' && cir == '-')) {
		int x = 0, y = 0;
		if (dir == 'F') y = 2;
		if (dir == 'B') x = 2;
		for (int i = 0; i < 3; i++) {
			char temp = Right[i][x];
			Right[i][x] = Up[y][i];
			Up[y][i] = Left[2 - i][y];
			Left[2 - i][y] = Down[x][2 - i];
			Down[x][2 - i] = temp;
		}
	}
	if ((dir == 'F' && cir == '-') || (dir == 'B' && cir == '+')) {
		int x = 0, y = 0;
		if (dir == 'F') y = 2;
		if (dir == 'B') x = 2;
		for (int i = 0; i < 3; i++) {
			char temp = Right[i][x];
			Right[i][x] = Down[x][2 - i];
			Down[x][2 - i] = Left[2 - i][y];
			Left[2 - i][y] = Up[y][i];
			Up[y][i] = temp;
		}
	}

	if ((dir == 'U' && cir == '+') || (dir == 'D' && cir == '-')) {
		int x = 0, y = 0;
		if (dir == 'U') y = 2;
		if (dir == 'D') x = 2;
		for (int i = 0; i < 3; i++) {
			char temp = Front[x][i];
			Front[x][i] = Right[x][i];
			Right[x][i] = Back[y][2 - i];
			Back[y][2 - i] = Left[x][i];
			Left[x][i] = temp;
		}
	}
	if ((dir == 'U' && cir == '-') || (dir == 'D' && cir == '+')) {
		int x = 0, y = 0;
		if (dir == 'U') y = 2;
		if (dir == 'D') x = 2;
		for (int i = 0; i < 3; i++) {
			char temp = Front[x][i];
			Front[x][i] = Left[x][i];
			Left[x][i] = Back[y][2 - i];
			Back[y][2 - i] = Right[x][i];
			Right[x][i] = temp;
		}
	}
}

void solve(char dir, char cir) {
	if (dir == 'U') rotate(Up, cir);
	if (dir == 'D') rotate(Down, cir);
	if (dir == 'L') rotate(Left, cir);
	if (dir == 'R') rotate(Right, cir);
	if (dir == 'F') rotate(Front, cir);
	if (dir == 'B') rotate(Back, cir);
	rotateSide(dir, cir);
}

void print() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << Up[i][j];
		}
		cout << '\n';
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		init();

		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			char dir, cir;
			cin >> dir >> cir;
			solve(dir, cir);
		}
		print();
	}

	return 0;
}