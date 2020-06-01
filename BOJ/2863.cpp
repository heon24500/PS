#include <iostream>
using namespace std;

int main() {
    double A, B, C, D;
    cin >> A >> B;
    cin >> C >> D;

    double max = (A / C) + (B / D);
    int ret = 0;

    for (int i = 0; i < 4; i++) {
        int temp = A;
        A = C;
        C = D;
        D = B;
        B = temp;

        double calc = (A / C) + (B / D);
        if (max < calc) {
            max = calc;
            ret = i + 1;
        }
    }

    cout << ret;

    return 0;
}