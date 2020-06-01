#include <iostream>
using namespace std;

int main() {
    while (true) {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;

        if (a1 == 0 && a2 == 0 && a3 == 0) break;

        int diff1 = a2 - a1, diff2 = a3 - a2;
        if (diff1 == diff2) cout << "AP " << a3 + diff1 << endl;
        else {
            diff1 = a2 / a1;
            cout << "GP " << a3 * diff1 << endl;
        }
    }

    return 0;
}