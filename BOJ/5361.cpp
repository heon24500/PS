#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        double sum = 0, cost[5] = { 350.34, 230.90, 190.55, 125.30, 180.90 };
        int num[5];

        for (int i = 0; i < 5; i++) {
            scanf("%d", &num[i]);
            sum += cost[i] * num[i];
        }

        printf("$%.2f\n", sum);
    }

    return 0;
}