#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int walks[4];
    for (int i = 0; i < 4; i++) {
        cin >> walks[i];
    }

    sort(walks, walks + 4);
    cout << walks[0] * walks[2];

    return 0;
}