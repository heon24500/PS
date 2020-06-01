#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, a, b, X[1000][1000];
    bool isFound = false;
    cin >> N >> a >> b;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> X[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        if (X[a - 1][b - 1] < X[a - 1][i] || X[a - 1][b - 1] < X[i][b - 1]) isFound = true;
    }

    if (isFound) cout << "ANGRY";
    else cout << "HAPPY";
}