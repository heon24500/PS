#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int character[4], cloth[4];
        for (int i = 0; i < 4; i++) {
            scanf("%d", &character[i]);
        }
        for (int i = 0; i < 4; i++) {
            scanf("%d", &cloth[i]);
            character[i] += cloth[i];

            if (i <= 1 && character[i] < 1) character[i] = 1;
            else if (i == 2 && character[i] < 0) character[i] = 0;
        }

        int point = 1 * character[0] + 5 * character[1] + 2 * character[2] + 2 * character[3];
        printf("%d\n", point);
    }
}