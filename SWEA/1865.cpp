/* 1865. 동철이의 일 분배 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 17;
double mat[N][N];
double ans;
int n;
bool visited[N];

void init()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mat[i][j] = 0;
		}
		visited[i] = 0;
	}
	ans = 0;
}

void solve(double result, int cnt)
{
	if (ans >= result * 100) return;
	if (cnt == n) {
		if (ans < result * 100) ans = result * 100;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		solve(result * mat[cnt][i], cnt + 1);
		visited[i] = false;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
				mat[i][j] /= 100;
			}
		}

		solve(1.0, 0);

		cout << fixed;
		cout.precision(6);
		cout << "#" << tc << " " << ans << '\n';
		init();
	}

	return 0;
}