#include <iostream>
#include <queue>
using namespace std;

#define L 305

queue<int> q[2];
bool visited[L][L];
int dist[L][L];
int d_x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int d_y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int l, sx, sy, dx, dy;
        cin >> l;
        cin >> sx >> sy;
        cin >> dx >> dy;

        visited[sy][sx] = true;
        q[0].push(sx);
        q[1].push(sy);
        dist[sy][sx] = 0;

        while (!q[0].empty()) {
            int x = q[0].front();
            int y = q[1].front();
            q[0].pop();
            q[1].pop();

            if (x == dx && y == dy) break;

            for (int i = 0; i < 8; i++) {
                int tx = x + d_x[i];
                int ty = y + d_y[i];

                if (tx >= 0 && tx < l && ty >= 0 && ty < l && !visited[ty][tx]) {
                    visited[ty][tx] = true;
                    q[0].push(tx);
                    q[1].push(ty);
                    dist[ty][tx] = dist[y][x] + 1;
                }
            }
        }

        cout << dist[dy][dx] << "\n";
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                visited[i][j] = false;
                dist[i][j] = 0;
            }
        }
        while (!q[0].empty()) {
            q[0].pop();
            q[1].pop();
        }
    }

    return 0;
}