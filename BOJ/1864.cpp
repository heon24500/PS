#include <iostream>
#include <string>
using namespace std;

int octToHum(string s) {
    int val = 1;
    int ret = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        int int_s;

        if (s[i] == '-') int_s = 0;
        else if (s[i] == '\\') int_s = 1;
        else if (s[i] == '(') int_s = 2;
        else if (s[i] == '@') int_s = 3;
        else if (s[i] == '?') int_s = 4;
        else if (s[i] == '>') int_s = 5;
        else if (s[i] == '&') int_s = 6;
        else if (s[i] == '%') int_s = 7;
        else if (s[i] == '/') int_s = -1;

        ret += int_s * val;
        val *= 8;
    }

    return ret;
}

int main() {
    while (true) {
        string str;
        cin >> str;

        if (str == "#") break;

        cout << octToHum(str) << endl;
    }

    return 0;
}