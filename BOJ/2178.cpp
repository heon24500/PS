#include <iostream>
#include <queue>
using namespace std;

#define N 105
#define M 105

queue<int> q[5];
int mat[N][M];
int d_x[4] = { 1, 0, -1, 0 };
int d_y[4] = { 0, 1, 0, -1 };
int dist[N][M];
bool visited[N][M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if (ch == '1') {
                mat[i][j] = 1;
            }
        }
    }

    int x = 0, y = 0;
    visited[y][x] = true;
    q[0].push(x);
    q[1].push(y);
    dist[0][0] = 1;

    while (!q[0].empty()) {
        x = q[0].front();
        y = q[1].front();
        q[0].pop();
        q[1].pop();

        for (int i = 0; i < 4; i++) {
            int tx = x + d_x[i];
            int ty = y + d_y[i];

            if (tx >= 0 && ty >= 0 && tx <= M - 1 && ty <= N - 1 && mat[ty][tx] == 1 && !visited[ty][tx]) {
                visited[ty][tx] = true;
                dist[ty][tx] = dist[y][x] + 1;
                q[0].push(tx);
                q[1].push(ty);
            }
        }
    }

    cout << dist[n - 1][m - 1];
}