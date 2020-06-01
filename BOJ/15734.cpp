#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int L, R, A;
    cin >> L >> R >> A;

    int ret = 0;
    while (true) {
        if (A > 0) {
            if (L > R) {
                R++;
                A--;
            }
            else if (L < R) {
                L++;
                A--;
            }
            else {
                if (A >= 2) {
                    R++;
                    L++;
                    A -= 2;
                }
            }
        }

        if (A <= 0 || (A < 2 && R == L)) break;
    }

    if (L > R) ret = 2 * R;
    else ret = 2 * L;

    cout << ret;
}