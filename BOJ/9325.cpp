#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int s, n;
        scanf("%d\n%d", &s, &n);

        int cost = s;

        while (n--) {
            int q, p;
            scanf("%d %d", &q, &p);
            cost += q * p;
        }

        printf("%d\n", cost);
    }

    return 0;
}