#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int times = 0;

    while (true) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if (a == 0 && b == 0 && c == 0) break;

        printf("Triangle #%d\n", ++times);

        if ((c != -1) && ((c <= a) || (c <= b))) printf("Impossible.\n\n");
        else {
            if (a == -1) printf("a = %.3f\n\n", sqrt(c * c - b * b));
            else if (b == -1) printf("b = %.3f\n\n", sqrt(c * c - a * a));
            else printf("c = %.3f\n\n", sqrt(a * a + b * b));
        }

    }

    return 0;
}