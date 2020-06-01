#include <iostream>
#include <algorithm>
using namespace std;

#define N 200

int ret[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ret[i];
    }

    sort(ret, ret + n);
    cout << ret[n / 2];

    return 0;
}