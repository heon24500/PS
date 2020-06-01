#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int k;
        scanf("%d", &k);

        for (int i = 0; i < k; i++) {
            printf("=");
        }

        printf("\n");
    }
}