#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, pair<int, int> > pipii;

const int N = 8, M = 8;
int n, m, cnt, ret = 1e9;
int mat[N][M];
vector<pipii> cctv;

vector<vector<int> > go(int y, int x, int d, vector<vector<int> > v) {
	if (d == 0) {
		while (x < m) {
			if (v[y][x] == 2) break;
			v[y][x++] = 1;
		}
	}
	else if (d == 1) {
		while (y < n) {
			if (v[y][x] == 2) break;
			v[y++][x] = 1;
		}
	}
	else if (d == 2) {
		while (x >= 0) {
			if (v[y][x] == 2) break;
			v[y][x--] = 1;
		}
	}
	else {
		while (y >= 0) {
			if (v[y][x] == 2) break;
			v[y--][x] = 1;
		}
	}
	return v;
}

void solve(int depth, vector<vector<int> > v) {
	if (depth == cnt) {
		int result = 0;
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].size(); j++) {
				if (v[i][j] == 0) result++;
			}
		}
		if (ret > result) ret = result;
		return;
	}

	pipii now = cctv[depth];
	int cctv_type = now.first;
	int y = now.second.first;
	int x = now.second.second;

	vector<vector<int> > tv;
	if (cctv_type == 1) {
		for (int i = 0; i < 4; i++) {
			tv = go(y, x, i, v);
			solve(depth + 1, tv);
		}
	}
	else if (cctv_type == 2) {
		for (int i = 0; i < 2; i++) {
			tv = go(y, x, i, v);
			tv = go(y, x, i + 2, tv);
			solve(depth + 1, tv);
		}
	}
	else if (cctv_type == 3) {
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				tv = go(y, x, 3, v);
				tv = go(y, x, 0, tv);
			}
			else {
				tv = go(y, x, i - 1, v);
				tv = go(y, x, i, tv);
			}
			solve(depth + 1, tv);
		}
	}
	else if (cctv_type == 4) {
		for (int i = 0; i < 4; i++) {
			bool flag = false;
			for (int j = 0; j < 4; j++) {
				if (i == j) continue;
				if (!flag) {
					tv = go(y, x, j, v);
					flag = true;
				}
				else tv = go(y, x, j, tv);
			}
			solve(depth + 1, tv);
		}
	}
	else if (cctv_type == 5) {
		vector<vector<int> > tv = go(y, x, 0, v);
		tv = go(y, x, 1, tv);
		tv = go(y, x, 2, tv);
		tv = go(y, x, 3, tv);
		solve(depth + 1, tv);
	}
}

int main() {
	cin >> n >> m;
	vector<vector<int> > v;
	for (int i = 0; i < n; i++) {
		vector<int> temp(m);
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] >= 1 && mat[i][j] <= 5) {
				cctv.push_back(make_pair(mat[i][j], make_pair(i, j)));
				cnt++;
			}
			if (mat[i][j] == 6) temp[j] = 2;
		}
		v.push_back(temp);
	}

	solve(0, v);
	cout << ret << '\n';

	return 0;
}