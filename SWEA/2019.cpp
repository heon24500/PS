#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ret = 1;
    cin >> n;
    cout << ret << " ";
    for (int i = 1; i <= n; i++) {
        ret *= 2;
        cout << ret << " ";
    }

    return 0;
}