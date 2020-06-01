#include <iostream>
using namespace std;

int main() {
    int moving = 0;

    for (int i = 0; i < 4; i++) {
        int inputNum;
        cin >> inputNum;
        moving += inputNum;
    }

    int x = moving / 60;
    int y = moving - (x * 60);

    cout << x << endl << y;

    return 0;
}