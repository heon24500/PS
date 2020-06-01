#include <iostream>
#include <algorithm>
using namespace std;

#define N 1005

int num[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num, num + n);
    for (int i = 0; i < n; i++) {
        cout << num[i] << "\n";
    }

    return 0;
}