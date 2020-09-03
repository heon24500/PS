/* 2115. [모의 SW 역량테스트] 벌꿀채취 */
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

const int N = 10, M = 5;
int n, m, c;
int max_profit, ret;
int mat[N][N];
bool check[M];
vector<int> honey;
vector<pii> picked;

void powerset(int depth, int len, int profit) {
	if (len > c) return;

	if (depth == m) {
		if (max_profit < profit) max_profit = profit;
		return;
	}

	check[depth] = true;
	powerset(depth + 1, len + honey[depth], profit + honey[depth] * honey[depth]);
	check[depth] = false;
	powerset(depth + 1, len, profit);
}

void solve(int y, int x, int depth) {
	if (depth == 2) {
		int profit = 0;
		for (int i = 0; i < 2; i++) {
			int ny = picked[i].first;
			int nx = picked[i].second;
			honey.clear();
			for (int j = nx; j < nx + m; j++) {
				honey.push_back(mat[ny][j]);
			}
			max_profit = 0;
			powerset(0, 0, 0);
			profit += max_profit;
		}
		if (ret < profit) ret = profit;

		return;
	}

	for (int i = y; i < n; i++) {
		for (int j = 0; j < n - m + 1; j++) {
			if (depth == 1 && i == y && j < x + m) continue;
			picked.push_back(make_pair(i, j));
			solve(i, j, depth + 1);
			picked.pop_back();
		}
	}
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m >> c;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
			}
		}

		ret = 0;
		solve(0, 0, 0);
		cout << "#" << tc << " " << ret << '\n';
	}

	return 0;
}