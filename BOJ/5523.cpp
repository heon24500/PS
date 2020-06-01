#include <iostream>
using namespace std;

int main() {
    int N, A_cnt = 0, B_cnt = 0;
    scanf("%d", &N);

    while (N--) {
        int A, B;
        scanf("%d %d", &A, &B);

        if (A > B) A_cnt++;
        else if (A < B) B_cnt++;
    }

    printf("%d %d", A_cnt, B_cnt);

    return 0;
}