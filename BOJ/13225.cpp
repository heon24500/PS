#include <iostream>
using namespace std;

int main() {
    int C;
    scanf("%d", &C);

    while (C--) {
        int n, cnt = 0;
        scanf("%d", &n);

        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) cnt++;
        }

        printf("%d %d\n", n, cnt + 1);
    }
}