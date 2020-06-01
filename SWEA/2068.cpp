#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int max = 0;

        for (int j = 0; j < 10; j++) {
            int num;
            cin >> num;
            if (max < num) max = num;
        }

        cout << "#" << i << " " << max << "\n";
    }

    return 0;
}