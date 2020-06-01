#include <iostream>
using namespace std;

int main() {
    while (true) {
        int N, width = 1;
        cin >> N;

        if (N == 0) break;

        while (N > 0) {
            int a = N % 10;
            N /= 10;
            width += 1;

            if (a == 1) width += 2;
            else if (a == 0) width += 4;
            else width += 3;
        }

        cout << width << endl;
    }

    return 0;
}