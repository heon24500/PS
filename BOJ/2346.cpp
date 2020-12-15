#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	deque<pii> dq;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		dq.push_back({ i, num });
	}

	int idx = dq.front().first;
	int num = dq.front().second;
	dq.pop_front();
	cout << idx << " ";

	while (!dq.empty()) {
		if (num > 0) {
			while (--num != 0) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			while (num != 0) {
				dq.push_front(dq.back());
				dq.pop_back();
				num++;
			}
		}

		idx = dq.front().first;
		num = dq.front().second;
		dq.pop_front();
		cout << idx << " ";
	}

	return 0;
}