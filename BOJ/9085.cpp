#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, sum = 0;
        scanf("%d", &N);

        while (N--) {
            int num;
            scanf("%d", &num);
            sum += num;
        }

        printf("%d\n", sum);
    }

    return 0;
}