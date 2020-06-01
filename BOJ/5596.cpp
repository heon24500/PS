#include <iostream>
using namespace std;

int main() {
    int S = 0, T = 0, temp;

    for (int i = 0; i < 4; i++) {
        cin >> temp;
        S += temp;
    }
    for (int i = 0; i < 4; i++) {
        cin >> temp;
        T += temp;
    }

    if (S >= T) cout << S;
    else cout << T;

    return 0;
}