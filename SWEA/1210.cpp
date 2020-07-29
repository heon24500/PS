/* 1210. [S/W 문제해결 기본] 2일차 - Ladder1 */
// 2가 도착지지만, 반대로 생각해서 2를 출발지로 탐색
// 좌나 우로 갈 수 있으면 막힐때까지 간 뒤 위로 한칸 이동 -> 반복
#include <iostream>
using namespace std;

int arr[100][100];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 0; t < 10; t++) {
		int t_num;
		cin >> t_num;

		int y = 99, x = 0;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 2) x = j;
			}
		}

		while (y > 0) {
			if (x - 1 >= 0 && arr[y][x - 1] == 1) {
				while (x - 1 >= 0 && arr[y][x - 1] == 1) x--;
			}
			else if (x + 1 < 100 && arr[y][x + 1] == 1) {
				while (x + 1 < 100 && arr[y][x + 1] == 1) x++;
			}
			y--;
		}

		cout << "#" << t_num << " " << x << '\n';
	}

	return 0;
}