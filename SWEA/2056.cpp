#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        bool flag = false;
        string str;
        cin >> str;

        if (str[4] == '1') {
            if (str[5] == '0' || str[5] == '2') {
                if (str[6] == '0' && str[7] >= '1' && str[7] <= '9') flag = true;
                else if (str[6] >= '1' && str[6] <= '2' && str[7] >= '0' && str[7] <= '9') flag = true;
                else if (str[6] == '3' && str[7] >= '0' && str[7] <= '1') flag = true;
            }
            else if (str[5] == '1') {
                if (str[6] == '0' && str[7] >= '1' && str[7] <= '9') flag = true;
                else if (str[6] >= '1' && str[6] <= '2' && str[7] >= '0' && str[7] <= '9') flag = true;
                else if (str[6] == '3' && str[7] == '0') flag = true;
            }
        }
        else if (str[4] == '0') {
            if (str[5] == '1' || str[5] == '3' || str[5] == '5' || str[5] == '7' || str[5] == '8') {
                if (str[6] == '0' && str[7] >= '1' && str[7] <= '9') flag = true;
                else if (str[6] >= '1' && str[6] <= '2' && str[7] >= '0' && str[7] <= '9') flag = true;
                else if (str[6] == '3' && str[7] >= '0' && str[7] <= '1') flag = true;
            }
            else if (str[5] == '2') {
                if (str[6] == '0' && str[7] >= '1' && str[7] <= '9') flag = true;
                else if (str[6] == '1' && str[7] >= '0' && str[7] <= '9') flag = true;
                else if (str[6] == '2' && str[7] >= '0' && str[7] <= '8') flag = true;
            }
            else if (str[5] == '4' || str[5] == '6' || str[5] == '9') {
                if (str[6] == '0' && str[7] >= '1' && str[7] <= '9') flag = true;
                else if (str[6] >= '1' && str[6] <= '2' && str[7] >= '0' && str[7] <= '9') flag = true;
                else if (str[6] == '3' && str[7] == '0') flag = true;
            }
        }

        if (flag) {
            cout << "#" << i << " ";
            for (int j = 0; j < 4; j++) {
                cout << str[j];
            }
            cout << "/" << str[4] << str[5] << "/" << str[6] << str[7] << "\n";
            flag = false;
        }
        else cout << "#" << i << " -1" << "\n";
    }

    return 0;
}