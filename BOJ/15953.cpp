#include <iostream>
using namespace std;

int main() {
    int T, a, b;
    int codeFest_1[6] = { 5000000, 3000000, 2000000, 500000, 300000, 100000 };
    int codeFest_2[5] = { 5120000, 2560000, 1280000, 640000, 320000 };

    cin >> T;
    for (int i = 0; i < T; i++) {
        int result = 0;

        cin >> a >> b;

        if (a == 0) result += 0;
        else {
            if (a <= 1) {
                result += codeFest_1[0];
            }
            else if (a <= 3) {
                result += codeFest_1[1];
            }
            else if (a <= 6) {
                result += codeFest_1[2];
            }
            else if (a <= 10) {
                result += codeFest_1[3];
            }
            else if (a <= 15) {
                result += codeFest_1[4];
            }
            else if (a <= 21) {
                result += codeFest_1[5];
            }
        }

        if (b == 0) result += 0;
        else {
            if (b <= 1) {
                result += codeFest_2[0];
            }
            else if (b <= 3) {
                result += codeFest_2[1];
            }
            else if (b <= 7) {
                result += codeFest_2[2];
            }
            else if (b <= 15) {
                result += codeFest_2[3];
            }
            else if (b <= 31) {
                result += codeFest_2[4];
            }
        }

        cout << result << endl;
    }

    return 0;
}