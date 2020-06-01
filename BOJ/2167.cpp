#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, arr[300][300], K;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> K;
    while (K--) {
        int sum = 0;
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        for (int a = i - 1; a < x; a++) {
            for (int b = j - 1; b < y; b++) {
                sum += arr[a][b];
            }
        }
        cout << sum << "\n";
    }
}