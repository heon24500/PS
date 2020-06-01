#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, sum = 0;
        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);

            int max_num = max(max(a, b), max(b, c));
            if (max_num > 0) sum += max_num;
        }

        printf("%d\n", sum);
    }
}