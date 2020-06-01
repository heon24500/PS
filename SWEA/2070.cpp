#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int a, b;
        char ret;
        cin >> a >> b;
        if (a > b) ret = '>';
        else if (a < b) ret = '<';
        else ret = '=';

        cout << "#" << i << " " << ret << "\n";
    }

    return 0;
}