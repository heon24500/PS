#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define N 30

queue<int> q[2];
int d_x[4] = { 1, 0, -1, 0 };
int d_y[4] = { 0, 1, 0, -1 };
int mat[N][N];
bool visited[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            if (ch == '1') mat[i][j] = 1;
        }
    }

    int ret = 0, total[N * N];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 1 || visited[i][j]) continue;

            int num = 0;
            q[0].push(j);
            q[1].push(i);
            visited[i][j] = true;

            while (!q[0].empty()) {
                int x = q[0].front();
                int y = q[1].front();
                q[0].pop();
                q[1].pop();

                num++;

                for (int k = 0; k < 4; k++) {
                    int tx = x + d_x[k];
                    int ty = y + d_y[k];

                    if (tx >= 0 && tx < n && ty >= 0 && ty < n && mat[ty][tx] == 1 && !visited[ty][tx]) {
                        visited[ty][tx] = true;
                        q[0].push(tx);
                        q[1].push(ty);
                    }
                }
            }

            total[ret++] = num;
        }
    }

    sort(total, total + ret);

    cout << ret << "\n";
    for (int i = 0; i < ret; i++) {
        cout << total[i] << "\n";
    }
}