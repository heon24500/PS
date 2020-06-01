#include <iostream>
#include <algorithm>
using namespace std;

int ret[9], result[7];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    for (int i = 0; i < 9; i++) {
        cin >> ret[i];
        sum += ret[i];
    }

    int a, b;
    bool flag = false;
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            int test = sum - ret[i] - ret[j];

            if (test == 100) {
                a = i;
                b = j;
                flag = true;
                break;
            }
        }

        if (flag) break;
    }

    int index = 0;
    for (int i = 0; i < 9; i++) {
        if (i != a && i != b) result[index++] = ret[i];
    }

    sort(result, result + 7);
    for (int i = 0; i < 7; i++) {
        cout << result[i] << "\n";
    }
}