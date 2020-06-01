#include <iostream>
using namespace std;

int main() {
    int n, Q1 = 0, Q2 = 0, Q3 = 0, Q4 = 0, AXIS = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        if (x == 0 || y == 0) AXIS++;
        else {
            if (x > 0) {
                if (y > 0) Q1++;
                else Q4++;
            }
            else {
                if (y > 0) Q2++;
                else Q3++;
            }
        }
    }

    printf("Q1: %d\nQ2: %d\nQ3: %d\nQ4: %d\nAXIS: %d", Q1, Q2, Q3, Q4, AXIS);

    return 0;
}