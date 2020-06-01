#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    B += C;
    if (B >= 60) {
        A += B / 60;
        B %= 60;
    }

    if (A >= 24) A %= 24;

    cout << A << " " << B;

    return 0;
}