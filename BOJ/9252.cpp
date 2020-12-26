#include <iostream>
#include <vector>
using namespace std;

int mat[1001][1001];
string str1, str2;

vector<char> lcs(int y, int x) {
	vector<char> ret;
	while (mat[y][x] != 0) {
		while (mat[y][x] == mat[y][x - 1]) x--;
		while (str1[y - 1] != str2[x - 1]) y--;
		ret.push_back(str1[y - 1]);
		y--;
		x--;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str2 >> str1;
	for (int i = 0; str1[i]; i++) {
		for (int j = 0; str2[j]; j++) {
			if (str1[i] == str2[j]) mat[i + 1][j + 1] = mat[i][j] + 1;
			else mat[i + 1][j + 1] = max(mat[i][j + 1], mat[i + 1][j]);
		}
	}

	cout << mat[str1.length()][str2.length()] << '\n';
	vector<char> ans = lcs(str1.length(), str2.length());
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];

	return 0;
}