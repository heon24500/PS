#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int num;
        cin >> num;

        int j = 0;
        while (num >= 1) {
            int ret = num % 2;
            num /= 2;

            if (ret == 1) cout << j << " ";
            j++;
        }
        cout << endl;
    }

    return 0;
}