#include <iostream>
using namespace std;

int main() {
    int T, dp[100];
    scanf("%d", &T);

    for (int i = 0; i < 100; i++) dp[i] = 0;

    while (T--) {
        int N;
        scanf("%d", &N);

        if (dp[N] != 0) printf("%d\n", dp[N]);
        else {
            int sum = 0;
            for (int i = 1; i <= N; i += 2) {
                sum += i;
            }
            dp[N] = sum;
            printf("%d\n", dp[N]);
        }
    }

    return 0;
}