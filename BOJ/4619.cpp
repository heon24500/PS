#include <iostream>
#include <math.h>
using namespace std;

int main() {
    while (true) {
        int B, N;
        cin >> B >> N;

        if (B == 0 && N == 0) break;

        int a = 1, last_val = 0, val = 1;
        while (true) {
            val = pow(a, N);

            if (val < B) {
                last_val = val;
                a++;
            }
            else break;
        }

        if (abs(B - last_val) > abs(B - val)) cout << a << endl;
        else cout << a - 1 << endl;
    }

    return 0;
}