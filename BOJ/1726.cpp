#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int> > pipii;

#define N 105
#define M 105

queue<pipii> q;
int d_x[4] = { 1, 0, -1, 0 };
int d_y[4] = { 0, 1, 0, -1 };
int mat[M][N];
int dist[4][M][N];
bool visited[4][M][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, sx, sy, sd, dx, dy, dd;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            if (ch == '1') mat[i][j] = 1;
        }
    }

    cin >> sy >> sx >> sd;
    cin >> dy >> dx >> dd;

    if (sd == 1) sd = 0;
    else if (sd == 2) sd = 2;
    else if (sd == 3) sd = 1;
    else sd = 3;

    if (dd == 1) dd = 0;
    else if (dd == 2) dd = 2;
    else if (dd == 3) dd = 1;
    else dd = 3;

    sy--;
    sx--;
    dy--;
    dx--;

    visited[sd][sy][sx] = true;
    q.push({ sd, {sy, sx} });

    while (!q.empty()) {
        pipii now = q.front();
        q.pop();

        int d = now.first;
        int y = now.second.first;
        int x = now.second.second;


        for (int i = 1; i < 4; i += 2) {
            int td = (d + i) % 4;
            if (!visited[td][y][x]) {
                visited[td][y][x] = true;
                q.push({ td, {y, x} });
                dist[td][y][x] = dist[d][y][x] + 1;
            }
        }

        for (int j = 1; j <= 3; j++) {
            int ty = y + j * d_y[d];
            int tx = x + j * d_x[d];

            if (ty < 0 || ty >= m || tx < 0 || tx >= n || mat[ty][tx] == 1) break;

            if (ty >= 0 && ty < m && tx >= 0 && tx < n && mat[ty][tx] == 0 && !visited[d][ty][tx]) {
                visited[d][ty][tx] = true;
                dist[d][ty][tx] = dist[d][y][x] + 1;
                q.push({ d, {ty, tx} });
            }

        }


        /*
        for (int i = 0; i < 4; i++) {
            int td = (d+i) % 4;
            if (i == 1 || i == 3) dist[i][y][x]++;
            else if (i == 2) dist[i][y][x] += 2;

            for (int j = 1; j <= 3; j++) {
                int ty = y + j * d_y[td];
                int tx = x + j * d_x[td];

                if (ty < 0 || ty >= m || tx < 0 || tx >= n || mat[ty][tx] == 1) break;

                if (ty >= 0 && ty < m && tx >= 0 && tx < n && mat[ty][tx] == 0 && !visited[td][ty][tx]) {
                    visited[td][ty][tx] = true;
                    dist[td][ty][tx] = dist[d][y][x] + 1;
                    q.push({td, {ty, tx}});

                    cout << "y = " << y << ", x = " << x << ", d = " << d << " : " << dist[d][y][x] << "\n";
                    cout << "ty = " << ty << ", tx = " << tx << ", td = " << td << " : " << dist[td][ty][tx] << "\n";

                }
            }
        }
        */
    }

    cout << dist[dd][dy][dx];
}