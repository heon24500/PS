#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, ret = 0;
    cin >> N;

    for (int i = 2; i <= N - 3; i += 2) {
        for (int j = 1; j <= (N - i - 2) / 2; j++) {
            int k = N - i - j;
            //cout << "(" << i << ", " << j << ", " << k << ") ";
            ret++;
        }
    }

    cout << ret;
}