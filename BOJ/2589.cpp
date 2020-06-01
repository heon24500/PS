#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

#define N 55
#define M 55

vector<int> ret;
queue<pii> q;
int d_y[4] = { 0, 1, 0, -1 };
int d_x[4] = { 1, 0, -1, 0 };
int mat[N][M];
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
            if (ch == 'L') mat[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] != 1) continue;

            visited[i][j] = true;
            q.push({ i, j });

            while (!q.empty()) {
                pii now = q.front();
                q.pop();

                int y = now.first;
                int x = now.second;

                for (int i = 0; i < 4; i++) {
                    int ty = y + d_y[i];
                    int tx = x + d_x[i];

                    if (ty >= 0 && ty < n && tx >= 0 && tx < m && mat[ty][tx] == 1 && !visited[ty][tx]) {
                        visited[ty][tx] = true;
                        dist[ty][tx] = dist[y][x] + 1;
                        q.push({ ty, tx });
                    }
                }
            }

            int max = 0;
            for (int a = 0; a < n; a++) {
                sort(dist[a], dist[a] + m);
                if (max < dist[a][m - 1]) max = dist[a][m - 1];
            }

            ret.push_back(max);

            for (int a = 0; a < n; a++) {
                for (int b = 0; b < m; b++) {
                    visited[a][b] = false;
                    dist[a][b] = 0;
                }
            }

            while (!q.empty()) {
                q.pop();
            }
        }
    }

    sort(ret.begin(), ret.end());
    cout << ret[ret.size() - 1];
}