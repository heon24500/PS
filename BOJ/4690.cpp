#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int a = 1, b = 1, c = 1, d = 1;

    while (a <= 100) {
        int pa = pow(a, 3);

        for (b = 2; b < a; b++) {
            int pb = pow(b, 3);

            for (c = b; c < a; c++) {
                int pc = pow(c, 3);

                for (d = c; d < a; d++) {
                    int pd = pow(d, 3);

                    if (pa == pb + pc + pd) cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
                }
            }
        }

        a++;
    }

    return 0;
}