#include <iostream>
#include <algorithm>
using namespace std;

#define N 1005
int a[N];
int LIS[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i - 1; j++) {
            if (a[i] > a[j] && LIS[i] < LIS[j] + 1) LIS[i] = LIS[j] + 1;
        }
    }

    sort(LIS, LIS + n + 1);
    cout << LIS[n];

    return 0;
}