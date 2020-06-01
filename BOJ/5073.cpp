#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        int len[3];
        for (int i = 0; i < 3; i++) cin >> len[i];

        if (len[0] == 0 && len[1] == 0 && len[2] == 0) break;

        sort(len, len + 3);

        if (len[0] + len[1] <= len[2]) cout << "Invalid" << endl;
        else {
            if (len[0] == len[1]) {
                if (len[0] == len[2]) cout << "Equilateral" << endl;
                else cout << "Isosceles" << endl;
            }
            else if (len[0] == len[2]) cout << "Isosceles" << endl;
            else if (len[1] == len[2]) cout << "Isosceles" << endl;
            else cout << "Scalene" << endl;
        }
    }

    return 0;
}