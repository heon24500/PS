#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long N, M, ret = 1;
    cin >> N >> M;

    while (N--) {
        long a;
        cin >> a;
        a %= M;
        ret *= a;
        ret %= M;
    }
    cout << ret;
}