#include <iostream>
using namespace std;

const int N = 1005;
int n;
char mat[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}

	int heart_y = 0, heart_x = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] == '*' && mat[i - 1][j] == '*' && mat[i + 1][j] == '*' && mat[i][j - 1] == '*' && mat[i][j + 1] == '*') {
				heart_y = i;
				heart_x = j;
			}
		}
	}

	int body = 0, left_arm = 0, right_arm = 0, left_leg = 0, right_leg = 0;
	int y = heart_y, x = heart_x;
	while (mat[y][x - 1] == '*') {
		left_arm++;
		x--;
	}
	x = heart_x;
	while (mat[y][x + 1] == '*') {
		right_arm++;
		x++;
	}
	x = heart_x;
	while (mat[y + 1][x] == '*') {
		body++;
		y++;
	}
	y++;
	int temp = y;
	while (mat[y][x - 1] == '*') {
		left_leg++;
		y++;
	}
	while (mat[temp][x + 1] == '*') {
		right_leg++;
		temp++;
	}


	cout << heart_y << " " << heart_x << '\n';
	cout << left_arm << " " << right_arm << " " << body << " " << left_leg << " " << right_leg;

	return 0;
}