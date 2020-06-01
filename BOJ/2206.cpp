#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int> > pipii;

#define N 1005
#define M 1005


int map[N][M];
int dist[2][N][M];
bool visited[2][N][M];
queue<pipii> q;

int d_y[4] = { 0,1,0,-1 };
int d_x[4] = { 1,0,-1,0 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if (ch == '1') map[i][j] = 1;
        }
    }

    dist[0][0][0] = 1;
    visited[0][0][0] = true;
    q.push({ 0, {0,0} });

    while (!q.empty()) {
        pipii now = q.front();
        q.pop();

        int wall = now.first;
        int x = now.second.first;
        int y = now.second.second;


        for (int i = 0; i < 4; i++) {
            int ty = y + d_y[i];
            int tx = x + d_x[i];

            if (ty >= 0 && ty < n && tx >= 0 && tx < m) {
                int twall = wall + map[ty][tx];
                if (twall < 2 && !visited[twall][ty][tx]) {
                    dist[twall][ty][tx] = dist[wall][y][x] + 1;
                    visited[twall][ty][tx] = true;
                    q.push({ twall,{tx,ty} });
                }
            }
        }
    }

    if (!visited[0][n - 1][m - 1]) dist[0][n - 1][m - 1] = 1000000000;
    if (!visited[1][n - 1][m - 1]) dist[1][n - 1][m - 1] = 1000000000;

    int ans = 1000000000;
    if (dist[0][n - 1][m - 1] < ans) ans = dist[0][n - 1][m - 1];
    if (dist[1][n - 1][m - 1] < ans) ans = dist[1][n - 1][m - 1];

    if (ans == 1000000000) cout << "-1";
    else cout << ans;


}