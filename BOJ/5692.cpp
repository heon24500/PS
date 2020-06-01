#include <iostream>
using namespace std;

int main() {
    while (true) {
        int n;
        scanf("%d", &n);

        if (n == 0) break;

        int val = 1, i = 1, ret = 0;
        while (n > 0) {
            val *= i;
            ret += val * (n % 10);
            n /= 10;
            i++;
        }

        printf("%d\n", ret);
    }

    return 0;
}