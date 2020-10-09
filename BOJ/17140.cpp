#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

const int N = 101;
int r, c, k, t, rlen = 3, clen = 3;
int mat[N][N];

int solve() {
	while (true) {
		if (mat[r][c] == k) return t;
		if (t >= 100) return -1;
		t++;

		if (rlen >= clen) {
			int max_len = 0;
			for (int i = 1; i <= rlen; i++) {
				vector<pii> v;
				for (int j = 1; j <= clen; j++) {
					if (mat[i][j] == 0) continue;
					int len = v.size();
					bool flag = false;
					int l;
					for (l = 0; l < len; l++) {
						if (v[l].second == mat[i][j]) {
							flag = true;
							break;
						}
					}
					if (flag) v[l].first++;
					else v.push_back({ 1, mat[i][j] });
				}

				sort(v.begin(), v.end());
				int len = v.size();
				int idx = 1;
				for (int j = 0; j < len; j++) {
					mat[i][idx++] = v[j].second;
					mat[i][idx++] = v[j].first;
				}
				max_len = max(max_len, idx - 1);
				for (int j = idx; j <= clen; j++) {
					mat[i][j] = 0;
				}
			}
			clen = max_len;
		}
		else {
			int max_len = 0;
			for (int i = 1; i <= clen; i++) {
				vector<pii> v;
				for (int j = 1; j <= rlen; j++) {
					if (mat[j][i] == 0) continue;
					int len = v.size();
					bool flag = false;
					int l;
					for (l = 0; l < len; l++) {
						if (v[l].second == mat[j][i]) {
							flag = true;
							break;
						}
					}
					if (flag) v[l].first++;
					else v.push_back({ 1, mat[j][i] });
				}

				sort(v.begin(), v.end());
				int len = v.size();
				int idx = 1;
				for (int j = 0; j < len; j++) {
					mat[idx++][i] = v[j].second;
					mat[idx++][i] = v[j].first;
				}
				max_len = max(max_len, idx - 1);
				for (int j = idx; j <= rlen; j++) {
					mat[j][i] = 0;
				}
			}
			rlen = max_len;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> mat[i][j];
		}
	}
	cout << solve();

	return 0;
}