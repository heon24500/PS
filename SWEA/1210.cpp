/* 1210. [S/W �����ذ� �⺻] 2���� - Ladder1 */
// 2�� ����������, �ݴ�� �����ؼ� 2�� ������� Ž��
// �³� ��� �� �� ������ ���������� �� �� ���� ��ĭ �̵� -> �ݺ�
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