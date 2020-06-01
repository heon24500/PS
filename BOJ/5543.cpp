#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int burger[3], soda[2];

    for (int i = 0; i < 3; i++) {
        cin >> burger[i];
    }
    for (int i = 0; i < 2; i++) {
        cin >> soda[i];
    }

    sort(burger, burger + 3);
    sort(soda, soda + 2);

    cout << burger[0] + soda[0] - 50;

    return 0;
}