#include <iostream>
using namespace std;

int main() {
    int originChess[6] = { 1, 1, 2, 2, 2, 8 };
    int inputChess[6];

    for (int i = 0; i < 6; i++) {
        cin >> inputChess[i];

        cout << originChess[i] - inputChess[i] << " ";
    }

    return 0;
}