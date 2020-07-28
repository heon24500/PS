/* 1220. [S/W �����ذ� �⺻] 5���� - Magnetic */
// �� N��/�Ʒ� S�� �ڼ�ü�� �پ��ִ� ������ 1���� ����������
// ���� �߽����� ���� �˻��ϸ� 1, 2�� (���� ���� ����) ���ӵǴ� ����� ���� count�Ͽ� ���
#include <iostream>
#include <vector>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 0; t < 10; t++) {
		int len;
		cin >> len;

		vector<vector<int> > table;
		for (int i = 0; i < len; i++) {
			vector<int> temp;
			for (int j = 0; j < len; j++) {
				int num;
				cin >> num;
				temp.push_back(num);
			}
			table.push_back(temp);
		}

		int ret = 0;
		for (int i = 0; i < 100; i++) {
			bool flag = false;
			for (int j = 0; j < 100; j++) {
				if (table[j][i] == 1) flag = true;
				if (table[j][i] == 2 && flag) {
					ret++;
					flag = false;
				}
			}
		}

		cout << "#" << t + 1 << " " << ret << '\n';
	}

	return 0;
}