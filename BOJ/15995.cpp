#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, m, x = 1;
    cin >> a >> m;

    while (true) {
        if ((a * x) % m == 1) {
            cout << x;
            break;
        }
        x++;
    }
}