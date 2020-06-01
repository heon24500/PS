#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N, K;
        scanf("%d %d", &N, &K);

        int kids = 0;
        for (int j = 0; j < N; j++) {
            int candy;
            scanf("%d", &candy);

            kids += candy / K;
        }

        printf("%d\n", kids);
    }

    return 0;
}