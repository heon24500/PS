#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, m, cnt = 0;
        scanf("%d %d", &n, &m);

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((i * i + j * j + m) % (i * j) == 0) cnt++;
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}