#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        long n, m;
        scanf("%ld %ld", &n, &m);

        printf("Scenario #%d:\n%ld\n\n", i, (m * (m + 1) - n * (n - 1)) / 2);
    }

    return 0;
}