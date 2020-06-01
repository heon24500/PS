#include <iostream>
using namespace std;

int main() {
    int T;
    char* dice[6] = { "Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh" };
    char* same_dice[6] = { "Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh" };
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        if (a < b) {
            int temp = b;
            b = a;
            a = temp;
        }

        printf("Case %d: ", i);
        if (a == b) printf("%s\n", same_dice[a - 1]);
        else if (a == 6 && b == 5) printf("Sheesh Beesh\n");
        else printf("%s %s\n", dice[a - 1], dice[b - 1]);
    }
}