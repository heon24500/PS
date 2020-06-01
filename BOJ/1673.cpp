#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    while (cin >> n >> k) {
        int chicken = n, stamp = n;
        n = 0;

        while (stamp >= k) {
            n = stamp / k;
            stamp %= k;
            chicken += n;
            stamp += n;
        }

        cout << chicken << "\n";
    }
}