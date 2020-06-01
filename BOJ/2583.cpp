#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

#define M 105
#define N 105
#define K 105

queue<pii> q;
int d_y[4] = { 0, 1, 0, -1 };
int d_x[4] = { 1, 0, -1, 0 };
int mat[M][N];
int dist[M][N];
bool visited[M][N];
vector<int> ret;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        for (int j = ly; j < ry; j++) {
            for (int l = lx; l < rx; l++) {
                mat[j][l] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1 || visited[i][j]) continue;

            visited[i][j] = true;
            q.push({ i, j });

            cnt++;
            int w = 0;
            while (!q.empty()) {
                pii now = q.front();
                q.pop();
                w++;

                int y = now.first;
                int x = now.second;

                for (int i = 0; i < 4; i++) {
                    int ty = y + d_y[i];
                    int tx = x + d_x[i];

                    if (ty >= 0 && ty < m && tx >= 0 && tx < n && mat[ty][tx] == 0 && !visited[ty][tx]) {
                        visited[ty][tx] = true;
                        dist[ty][tx] = dist[y][x] + 1;
                        q.push({ ty, tx });
                    }
                }
            }

            ret.push_back(w);
        }
    }

    cout << cnt << "\n";

    sort(ret.begin(), ret.end());
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
}