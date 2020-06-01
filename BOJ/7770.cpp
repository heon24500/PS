#include <iostream>
using namespace std;

int blocks(int n) {
    if (n == 1) return 1;
    else return blocks(n - 1) + 4 * (n - 1);
}

int main() {
    int n;
    scanf("%d", &n);

    int i = 0;
    while (n > 0) {
        i++;
        n -= blocks(i);
    }

    if (n < 0) i--;

    printf("%d", i);

    return 0;
}