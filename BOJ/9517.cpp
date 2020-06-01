#include <iostream>
using namespace std;

int main() {
    int K, N, bomb = 210;
    scanf("%d %d", &K, &N);

    for (int i = 0; i < N; i++) {
        int T;
        char Z;
        scanf("%d %c", &T, &Z);

        bomb -= T;
        if (bomb <= 0) {
            printf("%d", K);
            break;
        }


        if (Z == 'T') K++;
        if (K == 9) K = 1;
    }

    return 0;
}