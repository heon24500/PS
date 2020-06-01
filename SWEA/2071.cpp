#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int sum = 0;

        for (int j = 0; j < 10; j++) {
            int num;
            cin >> num;
            sum += num;
        }

        double ret = (double)sum / 10 + 0.5;

        cout << "#" << i << " " << (int)ret << "\n";
    }

    return 0;
}