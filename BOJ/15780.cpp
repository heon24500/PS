#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        int A;
        cin >> A;

        N -= (A + 1) / 2;
    }

    if (N <= 0) cout << "YES";
    else cout << "NO";
}