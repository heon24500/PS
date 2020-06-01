#include <iostream>
using namespace std;

int main() {
    bool is_under = false;
    int n, m;
    scanf("%d\n%d", &n, &m);

    int max = m;

    for (int i = 0; i < n; i++) {
        int in_cars, out_cars;
        scanf("%d %d", &in_cars, &out_cars);

        m = m + in_cars - out_cars;

        if (m < 0) {
            is_under = true;
            break;
        }

        if (max < m) max = m;
    }

    if (is_under) printf("0");
    else printf("%d", max);

    return 0;
}