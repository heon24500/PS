#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        printf("Pairs for %d: ", num);

        if (num > 2) printf("%d %d", 1, num - 1);

        for (int j = 2; j < (num + 1) / 2; j++) {
            int k = num - j;
            printf(", %d %d", j, k);
        }

        printf("\n");
    }

    return 0;
}