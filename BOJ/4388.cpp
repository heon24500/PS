#include <iostream>
using namespace std;

int main() {
    int lhs, rhs;
    while (true) {
        cin >> lhs >> rhs;

        if (lhs == 0 && rhs == 0) break;

        int carry = 0, carry_cnt = 0;
        while (lhs > 0 || rhs > 0) {
            int ln = lhs % 10;
            int rn = rhs % 10;

            if (ln + rn + carry >= 10) {
                carry = 1;
                carry_cnt++;
            }
            else carry = 0;

            lhs /= 10;
            rhs /= 10;
        }

        cout << carry_cnt << endl;
    }

    return 0;
}