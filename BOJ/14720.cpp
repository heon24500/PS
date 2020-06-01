#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N;
	cin >> N;

	int before_num, cnt = 0;
	bool flag = false;
	for (int i = 0; i < N; i++) {
		int store;
		cin >> store;

		if (!flag && store == 0) {
			flag = 1;
			cnt++;
			before_num = 0;
		}

		if (flag) {
			if (before_num == 2 && store == 0) {
				cnt++;
				before_num = 0;
			}
			else if (before_num + 1 == store) {
				cnt++;
				before_num = store;
			}
		}
	}

	cout << cnt;
}