#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N, D;
        scanf("%d %d", &N, &D);

        int cnt = 0;

        for (int j = 0; j < N; j++) {
            int v, f, c;
            scanf("%d %d %d", &v, &f, &c);

            double fuel = (double)f / (double)c;
            if (D <= v * fuel) cnt++;
        }

        printf("%d\n", cnt);
    }

    return 0;
}