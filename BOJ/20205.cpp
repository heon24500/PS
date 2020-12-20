#include <iostream>
using namespace std;

const int N = 10, K = 10;
int n, k;
int mat[N][N], ans[N * K][N * K];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            for (int y = i * k; y < i * k + k; y++) {
                for (int x = j * k; x < j * k + k; x++) {
                    ans[y][x] = mat[i][j];
                }
            }
        }
    }
    
    for (int i = 0; i < n * k; i++) {
        for (int j = 0; j < n * k; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}