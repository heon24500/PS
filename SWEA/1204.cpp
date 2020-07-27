/* 1204. [S/W �����ذ� �⺻] 1���� - �ֺ�� ���ϱ� */
// ������ �ε����� ����Ͽ� �Է� ������ ���� �ش� �ε����� �迭 �� +1 �� �� �ִ밪 ���
#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
		int t_num;
		cin >> t_num;

		int cnt[101];
		for (int i = 0; i <= 100; i++) {
			cnt[i] = 0;
		}

		int max_num = 0, ret = 0;
		for (int i = 0; i < 1000; i++) {
			int n;
			cin >> n;
			cnt[n]++;
			if ((max_num < cnt[n]) || (max_num == cnt[n] && ret < n)) {
				max_num = cnt[n];
				ret = n;
			}
		}

		cout << "#" << t_num << " " << ret << '\n';
	}

	return 0;
}