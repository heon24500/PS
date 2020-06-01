#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int A, B, C, ret = 0;
    cin >> A >> B >> C;

    while (true) {
        int ab = B - A, bc = C - B;

        if ((ab == 1) && (bc == 1)) break;

        if (ab > bc) {
            C = A + 1;

            int temp = C;
            C = B;
            B = temp;
        }
        else {
            A = C - 1;

            int temp = B;
            B = A;
            A = temp;
        }

        ret++;
    }

    cout << ret;

    return 0;
}