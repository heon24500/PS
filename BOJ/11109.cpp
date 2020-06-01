#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int d, n, s, p;
        scanf("%d %d %d %d", &d, &n, &s, &p);

        int s_time = s * n;
        int p_time = d + p * n;

        if (s_time < p_time) printf("do not parallelize\n");
        else if (s_time > p_time) printf("parallelize\n");
        else printf("does not matter\n");
    }
}