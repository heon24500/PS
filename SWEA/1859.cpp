#include <iostream>
using namespace std;

#define N 1000005
int price[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        long ret = 0;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> price[j];
        }

        int max = price[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            if (max < price[j]) max = price[j];
            else ret += max - price[j];
        }

        cout << "#" << i << " " << ret << "\n";
    }

    return 0;
}