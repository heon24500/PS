#include <iostream>
using namespace std;

int main() {
    int dice1, dice2, dice3, result;

    cin >> dice1 >> dice2 >> dice3;

    if (dice1 == dice2) {
        if (dice1 == dice3) result = 10000 + dice1 * 1000;
        else result = 1000 + dice1 * 100;
    }
    else if (dice1 == dice3) result = 1000 + dice1 * 100;
    else if (dice2 == dice3) result = 1000 + dice2 * 100;
    else {
        if (dice1 > dice2) {
            if (dice1 > dice3) result = dice1 * 100;
            else result = dice3 * 100;
        }
        else {
            if (dice2 > dice3) result = dice2 * 100;
            else result = dice3 * 100;
        }
    }

    cout << result;

    return 0;
}