#include <iostream>
#include <string>
using namespace std;

int main() {
    int sum = 0;
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        int strToInt;

        if (str[i] >= 'A') {
            strToInt = str[i] - 'A' + 10;
        }
        else {
            strToInt = str[i] - '0';
        }

        for (int j = str.length() - i; j > 1; j--) {
            strToInt *= 16;
        }

        sum += strToInt;
    }

    cout << sum;

    return 0;
}