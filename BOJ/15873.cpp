#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    int a, b;
    if (str.length() == 4) a = 10, b = 10;
    else if (str.length() == 3) {
        if ((str[0] == '1') && (str[1] == '0')) a = 10, b = str[2] - '0';
        else a = str[0] - '0', b = 10;
    }
    else a = str[0] - '0', b = str[1] - '0';

    cout << a + b;

    return 0;
}