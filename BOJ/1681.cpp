#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, L;
    cin >> N >> L;

    bool flag = false;
    int cnt = 0;
    long num = 0;

    while (true) {
        num++;
        long temp = num;

        while (temp) {
            if (temp % 10 == L) {
                flag = true;
                break;
            }
            temp /= 10;
        }

        if (flag) flag = false;
        else cnt++;

        if (cnt == N) break;
    }

    cout << num;
}