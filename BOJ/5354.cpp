#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int n;
        scanf("%d", &n);

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (j == 0 || j == n - 1) printf("#");
                else {
                    if (k == 0 || k == n - 1) printf("#");
                    else printf("J");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}