#include <iostream>
#include <algorithm>
using namespace std;

int height[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 10; i++) {
        int dump;
        cin >> dump;

        for (int j = 0; j < 100; j++) {
            cin >> height[j];
        }

        while (dump--) {
            sort(height, height + 100);
            if (height[0] == height[99]) break;

            height[0]++;
            height[99]--;
        }

        sort(height, height + 100);
        cout << "#" << i << " " << height[99] - height[0] << "\n";
    }

    return 0;
}