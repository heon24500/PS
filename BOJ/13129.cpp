#include <iostream>
using namespace std;

int main() {
    int A, B, N;
    scanf("%d %d %d", &A, &B, &N);

    for (int i = 1; i <= N; i++) {
        int height = B * i + A * N;
        printf("%d ", height);
    }
}