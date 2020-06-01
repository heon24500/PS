#include <iostream>
using namespace std;

#define N 305

int a[N];
int score[N][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    score[1][0] = a[1];
    score[2][0] = a[1] + a[2];
    score[2][1] = a[2];
    for (int i = 3; i <= n; i++) {
        score[i][0] = score[i - 1][1] + a[i];
        score[i][1] = max(score[i - 2][0], score[i - 2][1]) + a[i];
    }

    cout << max(score[n][0], score[n][1]);

    return 0;
}