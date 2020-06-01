#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        string str, str2, str3;
        cin >> str;

        for (int j = 0; j < 10; j++) {
            str2 += str[j];
            str3 = str[j + 1];
            for (int k = j + 2; k < j * 2 + 2; k++) {
                str3 += str[k];
            }
            if (str2.compare(str3) == 0) {
                cout << "#" << i << " " << j + 1 << "\n";
                break;
            }
        }
    }

    return 0;
}