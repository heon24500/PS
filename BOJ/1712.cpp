#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if (B >= C) cout << "-1";
    else {
        int result = A / (C - B) + 1;
        cout << result;
    }

    return 0;
}