#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, C, days;
        scanf("%d %d", &N, &C);

        if (N % C == 0) days = N / C;
        else days = N / C + 1;

        printf("%d\n", days);
    }
}