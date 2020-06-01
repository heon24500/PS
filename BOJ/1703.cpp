#include <iostream>
using namespace std;

int main() {
    while (true) {
        int a;
        cin >> a;
        if (a == 0) break;

        int leaves = 1;
        for (int i = 0; i < a; i++) {
            int sf, num;
            cin >> sf >> num;

            leaves *= sf;
            leaves -= num;
        }

        cout << leaves << endl;
    }

    return 0;
}