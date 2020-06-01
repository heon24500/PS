#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int H, W, N, N_H = 1, N_W = 1;
        scanf("%d %d %d", &H, &W, &N);

        while (--N) {
            if (N_H < H) N_H++;
            else {
                N_W++;
                N_H = 1;
            }
        }

        printf("%d%.2d\n", N_H, N_W);
    }

    return 0;
}