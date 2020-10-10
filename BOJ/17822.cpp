#include <iostream>
#include <queue>
using namespace std;

const int N = 51;
int n, m, t;
deque<int> dq[N];

void rotate(int x, int d, int k) {
	for (int i = x; i <= n; i += x) {
		if (d == 0) {
			for (int j = 0; j < k; j++) {
				int num = dq[i].back();
				dq[i].pop_back();
				dq[i].push_front(num);
			}
		}
		else {
			for (int j = 0; j < k; j++) {
				int num = dq[i].front();
				dq[i].pop_front();
				dq[i].push_back(num);
			}
		}
	}
}

int remove() {
	deque<int> temp[N];
	for (int i = 1; i <= n; i++) temp[i] = dq[i];

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (!dq[i][j]) continue;

			int x = j - 1;
			if (x < 0) x = m - 1;
			if (dq[i][j] == dq[i][x]) {
				temp[i][j] = temp[i][x] = 0;
				cnt++;
			}
			x = j + 1;
			if (x >= m) x = 0;
			if (dq[i][j] == dq[i][x]) {
				temp[i][j] = temp[i][x] = 0;
				cnt++;
			}

			int y = i - 1;
			if (y >= 1 && dq[i][j] == dq[y][j]) {
				temp[i][j] = temp[y][j] = 0;
				cnt++;
			}
			y = i + 1;
			if (y <= n && dq[i][j] == dq[y][j]) {
				temp[i][j] = temp[y][j] = 0;
				cnt++;
			}
		}
	}

	for (int i = 1; i <= n; i++) dq[i] = temp[i];
	return cnt;
}

int solve(int ret) {
	int ans = 0;
	if (ret == 0) {
		int sum = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (!dq[i][j]) continue;
				sum += dq[i][j];
				cnt++;
			}
		}

		double av = (double)sum / cnt;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (!dq[i][j]) continue;
				if (dq[i][j] > av) dq[i][j]--;
				else if (dq[i][j] < av) dq[i][j]++;
				ans += dq[i][j];
			}
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				ans += dq[i][j];
			}
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			dq[i].push_back(num);
		}
	}

	int ans = 0;
	for (int i = 0; i < t; i++) {
		int x, d, k;
		cin >> x >> d >> k;
		rotate(x, d, k);
		int ret = remove();
		ans = solve(ret);
	}
	cout << ans;

	return 0;
}