#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int> > pipii;

#define T 55
#define N 105

queue<pipii> q;
int mat[N][2];

bool visited[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int	t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n + 2; i++) {
			cin >> mat[i][0] >> mat[i][1];
		}

		q.push({ 0, {mat[0][0], mat[0][1]} });
		visited[0] = true;


		while (!q.empty()) {
			pipii now = q.front();
			q.pop();

			int num = now.first;
			int x = now.second.first;
			int y = now.second.second;

			for (int j = 0; j < n + 2; j++) {
				int tx = mat[j][0];
				int ty = mat[j][1];
				int d_x = abs(x - tx);
				int d_y = abs(y - ty);

				if (1000 >= (d_x + d_y) && !visited[j]) {
					visited[j] = true;
					q.push({ j, {tx, ty} });

				}
			}
		}

		if (visited[n + 1]) cout << "happy\n";
		else cout << "sad\n";


		for (int a = 0; a < n + 2; a++) {

			visited[a] = false;
		}

		while (!q.empty()) {
			q.pop();
		}
	}
}