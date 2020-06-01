#include <iostream>
using namespace std;

int main() {
    int N, points = 4, val = 2, ret = 1;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int nextVal = 2 * val - 1;
        points += val * ret + nextVal * ret;
        val = nextVal;
        ret *= 2;
    }

    cout << points;

    return 0;
}