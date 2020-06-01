#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    long A, B;
    cin >> A >> B;

    cout << (A + B) * (abs(B - A) + 1) / 2;

    return 0;
}