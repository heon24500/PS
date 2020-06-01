#include <iostream>
#include <string>
using namespace std;

int ball = 1;

void change(char ch) {
    if (ch == 'A') {
        if (ball == 1) ball = 2;
        else if (ball == 2) ball = 1;
    }
    else if (ch == 'B') {
        if (ball == 2) ball = 3;
        else if (ball == 3) ball = 2;
    }
    else {
        if (ball == 1) ball = 3;
        else if (ball == 3) ball = 1;
    }
}

int main() {
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        change(str[i]);
    }

    cout << ball;

    return 0;
}