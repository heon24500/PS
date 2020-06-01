#include <iostream>
using namespace std;

int main() {
    int N, point = 0, ret = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int result;
        cin >> result;

        if (result == 0) point = 0;
        else point++;

        ret += point;
    }

    cout << ret;

    return 0;
}