#include <iostream>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    int n = K / M;
    int m = K - (n * M);

    cout << n << " " << m;

    return 0;
}