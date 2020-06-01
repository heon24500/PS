#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int ret = N * (N - 1) * (N - 2) * (N - 3) / 24;
    cout << ret;

    return 0;
}