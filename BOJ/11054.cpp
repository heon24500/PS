#include <iostream>
#include <algorithm>
using namespace std;

#define N 1005

int a[N];
int LIS[N];
int ret[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 0; k <= j - 1; k++) {
                if (a[j] > a[k] && LIS[j] < LIS[k] + 1) LIS[j] = LIS[k] + 1;
            }
        }

        for (int j = i + 1; j <= n; j++) {
            for (int k = i; k <= j - 1; k++) {
                if (a[j] < a[k] && LIS[j] < LIS[k] + 1) LIS[j] = LIS[k] + 1;
            }
        }

        sort(LIS, LIS + n + 1);
        ret[i] = LIS[n];

        for (int j = 0; j <= n; j++) {
            LIS[j] = 0;
        }
    }

    sort(ret, ret + n + 1);
    cout << ret[n];

    return 0;
}