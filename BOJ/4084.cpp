#include <iostream>
#include <math.h>
using namespace std;

int main() {
    while (true) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a + b + c + d == 0) break;

        int k = 0;
        while (true) {
            if ((a == b) && (a == c) && (a == d)) break;

            int next_a = abs(a - b);
            int next_b = abs(b - c);
            int next_c = abs(c - d);
            int next_d = abs(d - a);
            a = next_a;
            b = next_b;
            c = next_c;
            d = next_d;

            k++;
        }

        cout << k << endl;
    }

    return 0;
}