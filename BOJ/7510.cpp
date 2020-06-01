#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int len[3];
        scanf("%d %d %d", &len[0], &len[1], &len[2]);

        sort(len, len + 3);

        printf("Scenario #%d:\n", i);
        if ((len[0] * len[0] + len[1] * len[1]) == len[2] * len[2]) printf("yes\n\n");
        else printf("no\n\n");
    }

    return 0;
}