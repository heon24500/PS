#include <iostream>
using namespace std;

int main() {
    int cnt = 1, isOdd = 0;
    while (true) {
        int n;
        cin >> n;

        if (n == 0) break;

        n *= 3;

        if (n % 2 == 0) {
            isOdd = 0;
            n /= 2;
        }
        else {
            isOdd = 1;
            n = (n + 1) / 2;
        }

        n *= 3;
        n /= 9;

        //if (isOdd) n = 2*n + 1;
        //else n *= 2;

        cout << cnt << ". ";
        if (isOdd) cout << "odd ";
        else cout << "even ";
        cout << n << endl;

        cnt++;
    }

    return 0;
}