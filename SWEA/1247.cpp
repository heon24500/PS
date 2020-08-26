/* 1247. [S/W 문제해결 응용] 3일차 - 최적 경로 */
#include <iostream>
using namespace std;

typedef pair<int, int> pii;
pii home, comp;
pii coord[10];
int n, ret = 1e9;
bool visited[10];

int dist(pii c1, pii c2) {
	return abs(c1.first - c2.first) + abs(c1.second - c2.second);
}

void solve(int depth, int len, pii now) {
	if (depth == 0) {
		int length = len + dist(now, comp);
		if (ret > length) ret = length;
		return;
	}

	if (len > ret) return;

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		solve(depth - 1, len + dist(now, coord[i]), coord[i]);
		visited[i] = false;
	}
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		cin >> home.first >> home.second;
		cin >> comp.first >> comp.second;
		for (int i = 0; i < n; i++) {
			cin >> coord[i].first >> coord[i].second;
		}

		solve(n, 0, home);
		cout << "#" << tc << " " << ret << '\n';
		ret = 1e9;
	}

	return 0;
}