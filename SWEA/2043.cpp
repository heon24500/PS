#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int p, k;
    cin >> p >> k;
    cout << p - k + 1;

    return 0;
}