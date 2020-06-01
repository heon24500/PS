#include <iostream>
using namespace std;

bool isEqual(int a, int b) {
    if ((b % 10) == 0) b -= (b / 10) * 10;

    if (a == b) return true;
    else return false;
}

int main() {
    int day, num[5], carNum = 0;
    cin >> day;
    for (int i = 0; i < 5; i++) {
        cin >> num[i];

        if (isEqual(day, num[i])) carNum++;
    }

    cout << carNum;

    return 0;
}