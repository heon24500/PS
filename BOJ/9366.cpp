#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int len[3];
        for (int j = 0; j < 3; j++) scanf("%d", &len[j]);

        sort(len, len + 3);
        printf("Case #%d: ", i);

        if (len[0] + len[1] <= len[2]) printf("invalid!\n");
        else {
            if (len[0] == len[1]) {
                if (len[1] == len[2]) printf("equilateral\n");
                else printf("isosceles\n");
            }
            else if (len[1] == len[2]) printf("isosceles\n");
            else printf("scalene\n");
        }
    }

    return 0;
}