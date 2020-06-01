#include <iostream>
using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) printf("*");
                else printf(".");
            }
            else {
                if (j % 2 == 0) printf(".");
                else printf("*");
            }
        }
        printf("\n");
    }
}