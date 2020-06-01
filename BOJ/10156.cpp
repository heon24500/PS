#include <iostream>
using namespace std;

int main() {
    int K, N, M;
    cin >> K >> N >> M;

    int pay = K * N;
    if (pay > M) cout << pay - M;
    else cout << "0";

    return 0;
}