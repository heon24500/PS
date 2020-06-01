#include <iostream>
using namespace std;

int main() {
    int N, flag = 0;
    scanf("%d", &N);

    while (N > 1) {
        if (flag) break;
        if (N % 2 == 0) N /= 2;
        else flag = 1;
    }

    if (flag) printf("0");
    else printf("1");
}