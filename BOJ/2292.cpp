#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int sum = 1, val = 1, ret = 1;
    while (true) {
        sum += val;
        val = ret * 6;
        if (sum > N) break;
        ret++;
    }

    cout << ret;
}