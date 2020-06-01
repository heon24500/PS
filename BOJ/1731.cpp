#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int diff1, diff2, last, num;
    cin >> last;
    cin >> num;
    diff1 = num - last;
    diff2 = num / last;
    last = num;
    cin >> num;
    if (diff1 == num - last) {
        for (int i = 0; i < N - 2; i++) {
            cin >> num;
        }
        num += diff1;
    }
    else {
        for (int i = 0; i < N - 2; i++) {
            cin >> num;
        }
        num *= diff2;
    }

    cout << num;
}