#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    if (str[0] == '0') cout << "0";
    if (str[0] == '1') cout << "1";
    if (str[0] == '2') cout << "10";
    if (str[0] == '3') cout << "11";
    if (str[0] == '4') cout << "100";
    if (str[0] == '5') cout << "101";
    if (str[0] == '6') cout << "110";
    if (str[0] == '7') cout << "111";

    for (int i = 1; i < str.length(); i++) {
        if (str[i] == '0') cout << "000";
        if (str[i] == '1') cout << "001";
        if (str[i] == '2') cout << "010";
        if (str[i] == '3') cout << "011";
        if (str[i] == '4') cout << "100";
        if (str[i] == '5') cout << "101";
        if (str[i] == '6') cout << "110";
        if (str[i] == '7') cout << "111";
    }

    return 0;
}