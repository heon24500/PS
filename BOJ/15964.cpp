#include <iostream>
using namespace std;

long calc(long a, long b) {
    long result = (a + b) * (a - b);

    return result;
}

int main() {
    long A, B;
    cin >> A >> B;

    cout << calc(A, B);

    return 0;
}