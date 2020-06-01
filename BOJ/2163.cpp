#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int ret = M - 1;
    ret += M * (N - 1);

    cout << ret;

    return 0;
}