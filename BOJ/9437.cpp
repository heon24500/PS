#include <iostream>
using namespace std;

int main() {
    while (true) {
        int N, P;
        scanf("%d %d", &N, &P);

        if (N == 0) break;

        int isFound = 0;

        for (int i = 1; i <= N / 2 - 1; i += 2) {
            int num[4];
            num[0] = i;
            num[1] = i + 1;
            num[2] = N - i;
            num[3] = N - i + 1;

            for (int j = 0; j < 4; j++) {
                if (num[j] == P) {
                    for (int k = 0; k < 4; k++) {
                        if (k != j) printf("%d ", num[k]);
                    }
                    isFound = 1;
                }
            }

            if (isFound) break;
        }

        printf("\n");
    }

    return 0;
}