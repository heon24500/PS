#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    int result = A;
    while (C--) {
        result ^= B;
    }
    printf("%d", result);
}