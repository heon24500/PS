#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int a, b;
        cin >> a >> b;
        cout << "#" << i << " " << a / b << " " << a % b << "\n";
    }

    return 0;
}