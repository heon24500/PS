/* 1002. �ͷ� */
/*
1. ������ ��ǥ�� ���� ���
   1) ũ�Ⱑ ���� ��� 2) ũ�Ⱑ �ٸ� ���
2. ������ ��ǥ�� �ٸ� ���
   1) ���� ���� �Ÿ� = �� ���� ũ���� �� -> �������� ����
   2) ���� ���� �Ÿ� > �� ���� ũ���� �� -> �� ���� ������ ����
   3) ���� ���� �Ÿ� < �� ���� ũ���� �� -> �� ���� ��ħ
      (1) �����ϴ� ��� (2) ������ �ʴ� ��� (3) �� ������ ������ ���
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		double circle[2][3];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> circle[i][j];
			}
		}

		double dist = 0;
		for (int i = 0; i < 2; i++) {
			dist += (circle[0][i] - circle[1][i]) * (circle[0][i] - circle[1][i]);
		}
		dist = sqrt(dist);
		double r1 = circle[0][2]; // ū ��
		double r2 = circle[1][2]; // ���� ��

		if (dist == 0) {
			// ������ ��ǥ�� ���� ���
			if (r1 == r2) cout << "-1\n";
			else cout << "0\n";
		}
		else {
			// ������ ��ǥ�� �ٸ� ���
			if (dist == r1 + r2) cout << "1\n";
			else if (dist > r1 + r2) cout << "0\n";
			else {
				if (r1 < r2) swap(r1, r2);
				
				if (dist + r2 == r1) {
					// �����ϴ� ���
					cout << "1\n";
				}
				else if (dist + r2 < r1) {
					// ������ �ʴ� ���
					cout << "0\n";
				}
				else {
					// �� ������ ������ ���
					cout << "2\n";
				}
			}
		}
	}

	return 0;
}