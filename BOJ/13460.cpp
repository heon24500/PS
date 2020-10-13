#include <iostream>
using namespace std;

const int N = 10, M = 10;
int n, m, ans = -1;
char mat[N][N];

// ���� �����
int moveUp() {
    int ret = 0;
    for (int x = 0; x < m; x++) {
        for (int y = 1; y < n; y++) {
            if (mat[y][x] != 'R' && mat[y][x] != 'B') continue;

            // �������̳� �Ķ��� ������ ���ٸ������ ���� �̵�
            int idx = y - 1;
            while (idx >= 0 && mat[idx][x] == '.') idx--;
            // ���ٸ� ���� �����̸�
            if (mat[idx][x] == 'O') {
                // ���� ���� �Ķ����� ��� ����, �������� ��� ��� ����
                if (mat[y][x] == 'B') return -1;
                ret = 1;
            }
            // �������� ���ۿ� �� ��찡 �ƴϸ� �� �̵�
            if (!ret) mat[idx + 1][x] = mat[y][x];
            // ���� �ٸ� ��ġ�� �̵��� ���� ���� ��ġ�� �ִ� �� ����
            if ((ret && mat[y][x] == 'R') || idx + 1 != y) mat[y][x] = '.';
        }
    }
    return ret;
}

int moveDown() {
    int ret = 0;
    for (int x = 0; x < m; x++) {
        for (int y = n - 2; y >= 0; y--) {
            if (mat[y][x] != 'R' && mat[y][x] != 'B') continue;

            int idx = y + 1;
            while (idx < n && mat[idx][x] == '.') idx++;
            if (mat[idx][x] == 'O') {
                if (mat[y][x] == 'B') return -1;
                ret = 1;
            }
            if (!ret) mat[idx - 1][x] = mat[y][x];
            if ((ret && mat[y][x] == 'R') || idx - 1 != y) mat[y][x] = '.';
        }
    }
    return ret;
}

int moveLeft() {
    int ret = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 1; x < m; x++) {
            if (mat[y][x] != 'R' && mat[y][x] != 'B') continue;

            int idx = x - 1;
            while (idx >= 0 && mat[y][idx] == '.') idx--;
            if (mat[y][idx] == 'O') {
                if (mat[y][x] == 'B') return -1;
                ret = 1;
            }
            if (!ret) mat[y][idx + 1] = mat[y][x];
            if ((ret && mat[y][x] == 'R') || idx + 1 != x) mat[y][x] = '.';
        }
    }
    return ret;
}

int moveRight() {
    int ret = 0;
    for (int y = 0; y < n; y++) {
        for (int x = m - 2; x >= 0; x--) {
            if (mat[y][x] != 'R' && mat[y][x] != 'B') continue;

            int idx = x + 1;
            while (idx < m && mat[y][idx] == '.') idx++;
            if (mat[y][idx] == 'O') {
                if (mat[y][x] == 'B') return -1;
                ret = 1;
            }
            if (!ret) mat[y][idx - 1] = mat[y][x];
            if ((ret && mat[y][x] == 'R') || idx - 1 != x) mat[y][x] = '.';
        }
    }
    return ret;
}

void backup(char mat_bak[N][M], bool isBackup) {
    if (isBackup) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                mat_bak[y][x] = mat[y][x];
            }
        }
    }
    else {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                mat[y][x] = mat_bak[y][x];
            }
        }
    }
}

bool isSame(char mat_bak[N][M]) {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (mat[y][x] != mat_bak[y][x]) return false;
        }
    }
    return true;
}

void solve(int depth) {
    if (depth > 10 || (ans != -1 && ans <= depth)) return;

    char mat_bak[N][M];
    backup(mat_bak, true); // ��Ʈ��ŷ ���ؼ� �迭 ���

    // �����¿�� ����
    int (*p[4])() = { moveUp, moveDown, moveLeft, moveRight };
    for (int i = 0; i < 4; i++) {
        int ret = p[i]();
        if (ret == 1) {
            // ������ �� ��� ans ���� �� ����
            if (ans == -1) ans = depth;
            else ans = min(ans, depth);
            backup(mat_bak, false);
            return;
        }
        // �Ķ����� �� ���
        if (ret == -1) {
            backup(mat_bak, false);
            continue;
        }
        if (isSame(mat_bak)) continue;  // ������ ������ ���� ���
        solve(depth + 1);
        backup(mat_bak, false);
    }
}

int main() {
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> mat[y][x];
        }
    }
    solve(1);
    cout << ans;

    return 0;
}