#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int Yonsei = 0, Korea = 0;

        for (int i = 0; i < 9; i++) {
            int Y, K;
            scanf("%d %d", &Y, &K);

            if (Y > K) Yonsei++;
            else if (Y < K) Korea++;
        }

        if (Yonsei > Korea) printf("Yonsei\n");
        else if (Yonsei < Korea) printf("Korea\n");
        else printf("Draw\n");
    }

    return 0;
}