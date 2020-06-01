#include <iostream>
using namespace std;

int main() {
    long N, M;
    cin >> N >> M;

    long result = N - M;
    if (result < 0) result = -result;

    cout << result;

    return 0;
}