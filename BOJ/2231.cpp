#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    bool isFound = false;
    for (int i = 1; i < N; i++) {
        int num = i, sum = i;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        if (sum == N) {
            cout << i;
            isFound = true;
            break;
        }
    }

    if (!isFound) cout << "0";
}