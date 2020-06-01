#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;

        int num = 1;
        while (b) {
            if (b & 1) num = (num * a) % 10;

            a = (a * a) % 10;
            b >>= 1;
        }

        if (num == 0) num = 10;

        cout << num << endl;
    }

    return 0;
}