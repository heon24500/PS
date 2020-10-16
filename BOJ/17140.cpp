#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int r, c, k, ans;
int mat[101][101];

void sortR(int rlen, int clen) {
	for (int i = 1; i <= rlen; i++) {
		vector<pii> v;
		for (int j = 1; j <= clen; j++) {
			if (mat[i][j] == 0) continue;
			int len = v.size();
			if (len == 0) v.push_back({ 1, mat[i][j] });
			else {
				bool flag = false;
				for (int l = 0; l < len; l++) {
					if (v[l].second != mat[i][j]) continue;
					v[l].first++;
					flag = true;
					break;
				}
				if (!flag) v.push_back({ 1, mat[i][j] });
			}
		}
		sort(v.begin(), v.end());
		int idx = 1, len = v.size();
		for (int l = 0; l < len; l++) {
			mat[i][idx++] = v[l].second;
			mat[i][idx++] = v[l].first;
		}
		while (idx <= 100) mat[i][idx++] = 0;
	}
}

void sortC(int rlen, int clen) {
	for (int j = 1; j <= clen; j++) {
		vector<pii> v;
		for (int i = 1; i <= rlen; i++) {
			if (mat[i][j] == 0) continue;
			int len = v.size();
			if (len == 0) v.push_back({ 1, mat[i][j] });
			else {
				bool flag = false;
				for (int l = 0; l < len; l++) {
					if (v[l].second != mat[i][j]) continue;
					v[l].first++;
					flag = true;
					break;
				}
				if (!flag) v.push_back({ 1, mat[i][j] });
			}
		}
		sort(v.begin(), v.end());
		int idx = 1, len = v.size();
		for (int l = 0; l < len; l++) {
			mat[idx++][j] = v[l].second;
			mat[idx++][j] = v[l].first;
		}
		while (idx <= 100) mat[idx++][j] = 0;
	}
}

void solve() {
	while (ans <= 100) {
		if (mat[r][c] == k) return;

		int rlen = 0, clen = 0;
		for (int i = 1; mat[i][1]; i++) {
			for (int j = 1; mat[i][j]; j++) {
				if (clen < j) clen = j;
			}
		}
		for (int j = 1; mat[1][j]; j++) {
			for (int i = 1; mat[i][j]; i++) {
				if (rlen < i) rlen = i;
			}
		}

		if (rlen >= clen) sortR(rlen, clen);
		else sortC(rlen, clen);
		ans++;
	}
	ans = -1;
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

	solve();
	cout << ans;

	return 0;
}