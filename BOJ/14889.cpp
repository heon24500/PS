#include <iostream>
#include <vector>
using namespace std;

const int N = 20;
int mat[N][N];
int n, min_diff = 1e9;
bool visited[N];

void solve(int idx, int depth, vector<int> v) {
	if (depth == n / 2) {
		int sum_start = 0, sum_link = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i] && visited[j]) sum_start += mat[i][j];
				if (!visited[i] && !visited[j]) sum_link += mat[i][j];
			}
		}

		int diff = abs(sum_start - sum_link);
		if (min_diff > diff) min_diff = diff;

		return;
	}

	for (int i = idx; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		v.push_back(i);
		solve(i, depth + 1, v);
		visited[i] = false;
		v.pop_back();
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	vector<int> v;
	solve(0, 0, v);
	cout << min_diff;

	return 0;
}