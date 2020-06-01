#include <iostream>
using namespace std;

int main() {
    int n, ret = 0;
    scanf("%d", &n);

    for (int i = 1; i <= (n + 1) / 2; i++) {
        for (int j = i; j <= n; j++) {
            if (i * j <= n) ret++;
        }
    }

    printf("%d", ret);

    return 0;
}