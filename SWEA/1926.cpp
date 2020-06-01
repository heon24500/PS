#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num = i, times = 0;
        if (num > 10) {
            while (num > 0) {
                if (num % 10 == 3 || num % 10 == 6 || num % 10 == 9) times++;
                num /= 10;
            }
        }
        else {
            if (num % 3 == 0) times = 1;
        }
        if (times > 0) {
            while (times--) {
                cout << "-";
            }
            cout << " ";
        }
        else cout << i << " ";
    }

    return 0;
}