#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
#define N 105

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		queue<pii> q;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			q.push({ i, num });
		}

		int ret = 0;
		while (true) {
			ret++;
			queue<pii> temp = q;
			int max = 0;
			while (!temp.empty()) {
				pii now = temp.front();
				temp.pop();

				int index = now.first;
				int point = now.second;
				if (max < point) max = point;
			}

			while (true) {
				pii now = q.front();
				int index = now.first;
				int point = now.second;

				if (point == max) break;

				q.pop();
				q.push(now);
			}

			pii now = q.front();
			q.pop();

			int index = now.first;
			int point = now.second;
			if (index == m) break;
		}

		cout << ret << "\n";
	}

	return 0;
}