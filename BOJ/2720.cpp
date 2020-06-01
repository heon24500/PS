#include <iostream>
using namespace std;

int main() {
    int T, coins[4] = { 25, 10, 5, 1 };
    cin >> T;

    for (int i = 0; i < T; i++) {
        int C;
        cin >> C;

        for (int j = 0; j < 4; j++) {
            int num = 0;
            if (C >= coins[j]) {
                num = C / coins[j];
                C -= num * coins[j];
            }

            cout << num << " ";
        }

        cout << endl;
    }

    return 0;
}