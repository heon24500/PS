/* 3752. 가능한 시험 점수 */
#include <iostream>
using namespace std;

int mat[101];
int n, ret;
bool visited[101][10001];

void init()
{
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 10001; j++) {
			visited[i][j] = false;
		}
	}
	ret = 0;
}

void solve(int k, int s)
{
	if (visited[k][s]) return;
	visited[k][s] = true;

	if (k == n) {
		ret++;
		return;
	}
	solve(k + 1, s);
	solve(k + 1, s + mat[k]);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> mat[i];
		}
		solve(0, 0);
		cout << "#" << tc << " " << ret << '\n';
		init();
	}

	return 0;
}