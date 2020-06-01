#include <iostream>
using namespace std;

int main() {
    int M, cups[3] = { 1, 2, 3 };
    cin >> M;

    while (M--) {
        int X, Y;
        cin >> X >> Y;

        if (X != Y) {
            int temp = cups[X - 1];
            cups[X - 1] = cups[Y - 1];
            cups[Y - 1] = temp;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (cups[i] == 1) cout << i + 1;
    }

    return 0;
}