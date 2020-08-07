/* 1861. 정사각형 방 */
#include <iostream>
using namespace std;

const int N = 1001;
int n, dist;
int a[N][N];
int moves[N][N];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
bool visited[N][N];

void init()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
	dist = 0;
}

bool isPossible(int ty, int tx, int y, int x)
{
	if (ty >= 0 && ty < n && tx >= 0 && tx < n && !visited[ty][tx] && a[ty][tx] == a[y][x] + 1) return true;
	else return false;
}

void dfs(int y, int x, int d)
{
	visited[y][x] = true;
	if (dist < d) dist = d;
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];
		if (!isPossible(ty, tx, y, x)) continue;
		dfs(ty, tx, d + 1);
		visited[ty][tx] = false;
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
				cin >> a[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist = 0;
				dfs(i, j, 1);
				moves[i][j] = dist;
				visited[i][j] = false;
			}
		}

		int ans_i = 0, ans_j = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((moves[ans_i][ans_j] < moves[i][j]) || (moves[ans_i][ans_j] == moves[i][j] && a[ans_i][ans_j] > a[i][j])) {
					ans_i = i;
					ans_j = j;
				}
			}
		}

		cout << "#" << tc << " " << a[ans_i][ans_j] << " " << moves[ans_i][ans_j] << '\n';
		init();
	}

	return 0;
}