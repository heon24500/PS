#include <iostream>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B;
    cin >> C >> D;

    int leftApples = C + B;
    int rightApples = A + D;

    if (leftApples > rightApples) cout << rightApples;
    else cout << leftApples;

    return 0;
}