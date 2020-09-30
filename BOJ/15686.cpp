#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

const int N = 50, M = 13;
int n, m, csize, ans = 1e9;
int mat[N][N];
bool visited[M];
vector<pii> chicken, house;

int dist() {
	int ret = 0;
	int hsize = house.size();
	for (int i = 0; i < hsize; i++) {
		int hy = house[i].first;
		int hx = house[i].second;
		int min_d = 1e9;

		for (int j = 0; j < csize; j++) {
			if (!visited[j]) continue;
			int cy = chicken[j].first;
			int cx = chicken[j].second;
			int d = abs(hy - cy) + abs(hx - cx);
			min_d = min(min_d, d);
		}

		ret += min_d;
	}

	return ret;
}

void solve(int depth, int idx) {
	if (depth == m) {
		ans = min(ans, dist());
		return;
	}

	for (int i = idx; i < csize; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		solve(depth + 1, i);
		visited[i] = false;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 1) house.push_back({ i, j });
			if (mat[i][j] == 2) chicken.push_back({ i, j });
		}
	}

	csize = chicken.size();
	solve(0, 0);
	cout << ans;

	return 0;
}