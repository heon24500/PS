#include <iostream>
#include <math.h>
using namespace std;

long bits(long n) {
    if (n == 0) return 1;
    else return bits(n - 1) + pow(2, n);
}

int main() {
    long N, b;
    cin >> N >> b;

    if (N <= bits(b)) cout << "yes";
    else cout << "no";

    return 0;
}