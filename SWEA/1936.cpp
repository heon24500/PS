#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    if (a == 1) {
        if (b == 2) cout << "B";
        else cout << "A";
    }
    else if (a == 2) {
        if (b == 1) cout << "A";
        else cout << "B";
    }
    else {
        if (b == 1) cout << "B";
        else cout << "A";
    }

    return 0;
}