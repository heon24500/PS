#include <iostream>
using namespace std;

int main() {
    int g_a1, g_a2, g_b1, g_b2;
    int s_a1, s_a2, s_b1, s_b2;
    scanf("%d %d %d %d", &g_a1, &g_b1, &g_a2, &g_b2);
    scanf("%d %d %d %d", &s_a1, &s_b1, &s_a2, &s_b2);

    int g_a = g_a1 + g_a2, g_b = g_b1 + g_b2;
    int s_a = s_a1 + s_a2, s_b = s_b1 + s_b2;

    int g_s = (g_a - s_a) + (g_b - s_b);
    if (g_s < 0) printf("Emma");
    else if (g_s > 0) printf("Gunnar");
    else printf("Tie");

    return 0;
}