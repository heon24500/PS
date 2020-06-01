#include <iostream>
using namespace std;

#define N 1005
int a[N];
int LIS[N];
int PATH[N];
int ret[N];

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
            if (a[i] > a[j] && LIS[i] < LIS[j] + 1) {
                LIS[i] = LIS[j] + 1;
                PATH[i] = j;
            }
        }
    }

    int max = 0, max_num = 0;
    for (int i = 1; i <= n; i++) {
        if (max < LIS[i]) {
            max = LIS[i];
            max_num = i;
        }
    }
    cout << max << "\n";

    int i = 0;
    ret[i++] = a[max_num];
    while (PATH[max_num] > 0) {
        ret[i++] = a[PATH[max_num]];
        max_num = PATH[max_num];
    }

    for (int j = i - 1; j >= 0; j--) {
        cout << ret[j] << " ";
    }

    return 0;
}