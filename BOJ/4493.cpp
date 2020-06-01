#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, lw = 0, rw = 0;
        cin >> n;

        for (int j = 0; j < n; j++) {
            char lhs, rhs;
            cin >> lhs >> rhs;

            if (lhs == 'R') {
                if (rhs == 'S') lw++;
                else if (rhs == 'P') rw++;
            }
            else if (lhs == 'S') {
                if (rhs == 'R') rw++;
                else if (rhs == 'P') lw++;
            }
            else {
                if (rhs == 'S') rw++;
                else if (rhs == 'R') lw++;
            }
        }

        if (lw > rw) cout << "Player 1" << endl;
        else if (lw < rw) cout << "Player 2" << endl;
        else cout << "TIE" << endl;
    }

    return 0;
}