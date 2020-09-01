/* 1258. [S/W 문제해결 응용] 7일차 - 행렬찾기 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

const int N = 100;
int n;
int mat[N][N];
vector<pii> ans;
bool visited[N][N];

bool comp(pii a, pii b) {
	if (a.first * a.second == b.first * b.second) return a.first < b.first;
	return a.first * a.second < b.first * b.second;
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}

	ans.clear();
}

void solve(int idx1, int idx2) {
	int idx_i, idx_j;
	for (idx_i = idx1; idx_i < n; idx_i++) {
		if (mat[idx_i][idx2] == 0) break;
	}
	for (idx_j = idx2; idx_j < n; idx_j++) {
		if (mat[idx1][idx_j] == 0) break;
	}

	for (int i = idx1; i < idx_i; i++) {
		for (int j = idx2; j < idx_j; j++) {
			visited[i][j] = true;
		}
	}

	ans.push_back(make_pair(idx_i - idx1, idx_j - idx2));
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] != 0 && !visited[i][j]) solve(i, j);
			}
		}

		sort(ans.begin(), ans.end(), comp);

		cout << "#" << tc << " " << ans.size() << " ";
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].first << " " << ans[i].second << " ";
		}
		cout << '\n';

		init();
	}

	return 0;
}