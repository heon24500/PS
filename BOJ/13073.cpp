#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int num, S1 = 0, S2 = 0, S3 = 0;
        scanf("%d", &num);

        for (int i = 1; i <= num; i++) {
            S1 += i;
            S2 += i * 2 - 1;
            S3 += i * 2;
        }

        printf("%d %d %d\n", S1, S2, S3);
    }
}