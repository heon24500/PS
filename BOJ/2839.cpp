#include <iostream>
using namespace std;

int main() {
	int n, bag_5kg, bag_3kg;
	cin >> n;

	if (n >= 5) {
		// 5kg �̻��� ���
		if (n % 5 == 0) {
			// 5kg ���������� ���� �� �ִ� ���
			bag_5kg = n / 5;
			cout << bag_5kg << endl;
		}
		else {
			// 5kg ���������� ���� �� ���� ���
			int max_5kg = n / 5; // 5kg ���� �ִ� ����

			// 5kg ������ ���� �� �ִ��� Ȯ��
			for (bag_5kg = max_5kg; bag_5kg > 0; bag_5kg--) {
				int n2 = n - bag_5kg * 5;
				if (n2 % 3 == 0) {
					// 3kg ������ ���� ���� ���� �� �ִ� ���
					bag_3kg = n2 / 3;
					cout << bag_5kg + bag_3kg << endl;
					return 0;
				}
				else {
					// 3kg ������ ���� ���� ���� �� ���� ���
					continue;
				}
			}

			// 5kg ������ ���� �� ���� ���
			if (n % 3 == 0) {
				// 3kg ������ ���� �� �ִ� ���
				bag_3kg = n / 3;
				cout << bag_3kg << endl;
			}
			else {
				// 3kg ������ ���� �� ���� ���
				cout << "-1" << endl;
			}
		}
	}
	else {
		// 5kg �̸��� ���
		if (n == 3) {
			cout << "1" << endl;
		}
		else {
			cout << "-1" << endl;
		}
	}

	return 0;
}