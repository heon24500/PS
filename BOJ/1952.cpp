#include <iostream>
using namespace std;

int main() {
    int M, N, ret = 1;
    cin >> M >> N;

    int i = 1;
    while ((M != 1) && (N != 1)) {
        if ((i % 2) != 0) M--;
        else N--;
        ret++;
        i++;
    }

    cout << ret;

    return 0;
}