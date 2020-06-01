#include <iostream>
#include <vector>
using namespace std;

#define N 305
#define M 25

int mat[N][M];
int dp[N][M];
int path[N][M];

void print_path(int money, int com)
{
	if (com == 0) return;

	print_path(path[money][com], com - 1);
	cout << money - path[money][com] << " ";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int money;
		cin >> money;
		for (int j = 1; j <= m; j++) {
			cin >> mat[money][j];
		}
	}



	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k <= j; k++) {
				if (dp[j][i] < dp[k][i - 1] + mat[j - k][i]) {
					dp[j][i] = dp[k][i - 1] + mat[j - k][i];
					path[j][i] = k;
				}
			}
		}
	}
	cout << dp[n][m] << "\n";
	print_path(n, m);

	return 0;

}
