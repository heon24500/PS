#include <iostream>
using namespace std;

int main() {
    int M, N, K;
    cin >> N >> M >> K;

    int result;
    int frontX = N - M;
    int backX = N - K;

    if (M > frontX) {
        if (M > K) result = K + frontX;
        else result = M + backX;
    }
    else {
        if (frontX > backX) result = backX + M;
        else result = frontX + K;
    }

    cout << result;

    return 0;
}