#include <iostream>
using namespace std;

int main() {
    int p[4], x, y, r;
    for (int i = 0; i < 4; i++) {
        scanf("%d", &p[i]);
    }

    scanf("%d %d %d", &x, &y, &r);

    int p_num = 0;
    for (int i = 0; i < 4; i++) {
        if (p[i] == x) p_num = i + 1;
    }

    printf("%d", p_num);
}