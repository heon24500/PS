#include <iostream>
using namespace std;

int main() {
    int T, button[3] = { 0, 0, 0 }, buttonTime[3] = { 300, 60, 10 };
    cin >> T;

    for (int i = 0; i < 3; i++) {
        if (T >= buttonTime[i]) {
            button[i] = T / buttonTime[i];
            T -= button[i] * buttonTime[i];
        }
    }

    if (T == 0) {
        for (int i = 0; i < 3; i++) {
            cout << button[i] << " ";
        }
    }
    else {
        cout << "-1";
    }

    return 0;
}