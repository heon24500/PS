#include <iostream>
using namespace std;

int main() {
    int a_attack, a_life, b_attack, b_life;
    scanf("%d %d", &a_attack, &a_life);
    scanf("%d %d", &b_attack, &b_life);

    while (a_life > 0 && b_life > 0) {
        a_life -= b_attack;
        b_life -= a_attack;
    }

    if (a_life > 0 && b_life <= 0) printf("PLAYER A");
    else if (a_life <= 0 && b_life > 0) printf("PLAYER B");
    else printf("DRAW");
}