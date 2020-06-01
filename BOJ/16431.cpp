#include <iostream>
using namespace std;

int main() {
    int Br, Bc, Dr, Dc, Jr, Jc;
    cin >> Br >> Bc;
    cin >> Dr >> Dc;
    cin >> Jr >> Jc;

    int flag = 0;
    while (flag == 0) {
        // B moved
        if (Br > Jr) Br--;
        else if (Br == Jr) {
            if (Bc == Jc) flag += 1;
        }
        else Br++;

        if (Bc > Jc) Bc--;
        else if (Bc < Jc) Bc++;

        // D moved
        if (Dr > Jr) Dr--;
        else if (Dr == Jr) {
            if (Dc > Jc) Dc--;
            else if (Dc == Jc) flag += 2;
            else Dc++;
        }
        else Dr++;
    }

    if (flag == 1) cout << "bessie";
    else if (flag == 2) cout << "daisy";
    else cout << "tie";

    return 0;
}