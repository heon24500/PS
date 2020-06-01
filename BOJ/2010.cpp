#include <iostream>
using namespace std;

int main() {
    int N, ret = 0;
    cin >> N;

    while (N--) {
        int M;
        cin >> M;

        if (N >= 1) M--;
        ret += M;
    }

    cout << ret;

    return 0;
}