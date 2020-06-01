#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int Q;
    cin >> Q;

    while (Q--) {
        int a;
        cin >> a;

        bool flag = true;
        while (true) {
            if (a == 1) break;

            if (a % 2 == 0) a /= 2;
            else {
                flag = false;
                break;
            }
        }

        cout << flag << "\n";
    }
}