/* 1225. [S/W 문제해결 기본] 7일차 - 암호생성기 */
#include <iostream>
#include <queue>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 0; t < 10; t++) {
		int t_num;
		cin >> t_num;

		queue<int> q;
		for (int i = 0; i < 8; i++) {
			int n;
			cin >> n;
			q.push(n);
		}

		int cnt = 1, now = -1;
		while (now != 0) {
			now = q.front() - cnt;
			if (now < 0) now = 0;
			q.pop();
			q.push(now);
			if (cnt == 5) cnt = 1;
			else cnt++;
		}

		cout << "#" << t_num << " ";
		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}
		cout << '\n';
	}

	return 0;
}