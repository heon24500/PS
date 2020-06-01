#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

#define N 305
#define M 305

queue<pii> q;
int mat[N][M];
int nums[N][M];
bool visited[N][M];
int d_x[4] = { 1, 0, -1, 0 };
int d_y[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, ret = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    while (true) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] || mat[i][j] == 0) continue;

                cnt++;
                q.push({ i, j });
                visited[i][j] = true;

                while (!q.empty()) {
                    pii now = q.front();
                    q.pop();

                    int y = now.first;
                    int x = now.second;

                    for (int i = 0; i < 4; i++) {
                        int ty = y + d_y[i];
                        int tx = x + d_x[i];

                        if (ty >= 0 && ty < n && tx >= 0 && tx < m && mat[ty][tx] != 0 && !visited[ty][tx]) {
                            visited[ty][tx] = true;
                            q.push({ ty, tx });
                        }
                    }
                }
            }
        }
        if (cnt > 1) break;

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                visited[i][j] = false;
                if (mat[i][j] == 0) continue;

                int num = 0;
                if (mat[i + 1][j] == 0) num++;
                if (mat[i][j + 1] == 0) num++;
                if (mat[i - 1][j] == 0) num++;
                if (mat[i][j - 1] == 0) num++;

                nums[i][j] = num;
            }
        }

        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] -= nums[i][j];
                if (mat[i][j] < 0) mat[i][j] = 0;
                if (mat[i][j] != 0) flag = false;
            }
        }
        ret++;
        if (flag) {
            ret = 0;
            break;
        }
    }

    cout << ret;

    return 0;
}