#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int A, B, num;
        scanf("%d %d", &A, &B);

        num = A / B;
        long sum = 0;
        for (int i = 1; i <= num; i++) {
            sum += 2 * i - 1;
        }

        printf("%ld\n", sum);
    }
}