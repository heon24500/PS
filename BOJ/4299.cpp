#include <iostream>
using namespace std;

int main() {
    int sum, diff;
    cin >> sum >> diff;

    if (sum == 0) {
        if (diff == 0) cout << "0 0";
        else cout << "-1";
    }
    for (int i = 0; i < sum; i++) {
        int b = sum - i;
        int diff_i = i - b;
        if (diff_i < 0) diff_i = -diff_i;

        if (diff == diff_i) {
            if (b > i) cout << b << " " << i;
            else cout << i << " " << b;
            break;
        }
        if (i == (sum - 1)) cout << "-1";
    }

    return 0;
}