#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while (N--) {
        string str;
        cin >> str;

        int lhs = 0, rhs = 0, val = 26 * 26;
        for (int i = 0; i < 3; i++) {
            lhs += (str[i] - 'A') * val;
            val /= 26;
        }

        val = 1000;
        for (int i = 4; i < 8; i++) {
            rhs += (str[i] - '0') * val;
            val /= 10;
        }

        if (abs(lhs - rhs) <= 100) cout << "nice\n";
        else cout << "not nice\n";
    }
}