#include <iostream>
using namespace std;

int main() {
    int goNum[5];
    int gumNum = 0;

    for (int i = 0; i < 5; i++) {
        cin >> goNum[i];

        gumNum += (goNum[i] * goNum[i]);
    }

    gumNum %= 10;

    cout << gumNum;

    return 0;
}