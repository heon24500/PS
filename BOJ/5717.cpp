#include <iostream>
using namespace std;

int main() {
    while (true) {
        int M, F;
        scanf("%d %d", &M, &F);
        if (M == 0 && F == 0) break;
        printf("%d\n", M + F);
    }

    return 0;
}