#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    float point;
    if (str[0] == 'A') point = 4.0;
    else if (str[0] == 'B') point = 3.0;
    else if (str[0] == 'C') point = 2.0;
    else if (str[0] == 'D') point = 1.0;
    else point = 0.0;

    if (point != 0.0) {
        if (str[1] == '+') point += 0.3;
        else if (str[1] == '-') point -= 0.3;
    }

    cout << fixed;
    cout.precision(1);
    cout << point;

    return 0;
}