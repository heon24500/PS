#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int candy, bro;
        scanf("%d %d", &candy, &bro);
        printf("You get %d piece(s) and your dad gets %d piece(s).\n", candy / bro, candy - (candy / bro) * bro);
    }

    return 0;
}