#include <iostream>
using namespace std;

int main() {
    int N, M, K, teams = 0;
    cin >> N >> M >> K;

    while (true) {
        int remain = N + M;
        if (remain - K < 3) break;
        if ((N < 2) || (M < 1)) break;

        N -= 2;
        M -= 1;
        teams++;
    }

    cout << teams;

    return 0;
}