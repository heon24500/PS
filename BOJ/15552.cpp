#include <stdio.h>

int main() {
    int i, a, b, cnt;
    scanf("%d", &cnt);

    for (i = 0; i < cnt; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}