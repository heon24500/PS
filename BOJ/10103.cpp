#include <iostream>
using namespace std;

int main() {
    int n, score1 = 100, score2 = 100;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int dice1, dice2;
        scanf("%d %d", &dice1, &dice2);

        if (dice1 < dice2) score1 -= dice2;
        else if (dice1 > dice2) score2 -= dice1;
    }

    printf("%d\n%d", score1, score2);

    return 0;
}