#include <iostream>
using namespace std;

int main() {
    int n, T, cnt = 0;
    scanf("%d %d", &n, &T);

    for (int i = 0; i < n; i++) {
        int job;
        scanf("%d", &job);
        T -= job;
        if (T >= 0) cnt++;
    }

    printf("%d", cnt);

    return 0;
}