#include <iostream>
using namespace std;

int main() {
    int N, T, C, P;
    int result = 0;
    int day = 1;
    cin >> N >> T >> C >> P;

    while (true) {
        day += T;
        if (day > N) break;

        result += C * P;
    }

    cout << result;

    return 0;
}