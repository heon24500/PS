#include <iostream>
using namespace std;

bool isYoonYear(int y) {
    if ((y % 4) == 0) {
        if (((y % 100) != 0) || ((y % 400) == 0)) return true;
    }

    return false;
}

int main() {
    int year;
    cin >> year;

    if (isYoonYear(year) == true) cout << "1";
    else cout << "0";

    return 0;
}