#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 25

vector<int> ret;
int s[N][N];
bool visited[N];

int calc_diff(int max) {
	vector<int> start, link;
	for (int i = 1; i <= max; i++) {
		if (visited[i]) start.push_back(i);
		else link.push_back(i);
	}

	int start_stats = 0, link_stats = 0;
	for (int i = 0; i < max / 2; i++) {
		for (int j = 0; j < max / 2; j++) {
			if (i == j) continue;
			start_stats += s[start[i]][start[j]];
			link_stats += s[link[i]][link[j]];
		}
	}

	int diff = abs(start_stats - link_stats);
	return diff;
}

void bfs(int num, int src, int max) {
	visited[src] = true;

	if (num == max / 2) {
		int diff = calc_diff(max);
		ret.push_back(diff);
		return;
	}

	for (int i = src + 1; i <= max; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		bfs(num + 1, i, max);
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> s[i][j];
		}
	}

	bfs(0, 0, n);
	sort(ret.begin(), ret.end());
	cout << ret[0];

	return 0;
}