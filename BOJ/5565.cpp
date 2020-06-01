#include <iostream>
using namespace std;

int main() {
    int total;
    scanf("%d", &total);

    for (int i = 0; i < 9; i++) {
        int cost;
        scanf("%d", &cost);

        total -= cost;
    }

    printf("%d", total);

    return 0;
}