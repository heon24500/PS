#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, sum = 0;
    cin >> n;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    cout << sum;

    return 0;
}