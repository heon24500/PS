#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        int num[3], sum = 0;
        for (int i = 0; i < 3; i++) {
            cin >> num[i];
            sum += num[i];
        }

        if (sum == 0) break;

        sort(num, num + 3);

        if ((num[0] * num[0] + num[1] * num[1]) == num[2] * num[2]) cout << "right" << endl;
        else cout << "wrong" << endl;
    }

    return 0;
}