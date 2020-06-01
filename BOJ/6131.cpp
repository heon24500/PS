#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int num = 0;
    for (int i = 1; i <= 500; i++) {
        for (int j = i; j <= 500; j++) {
            if (j * j - i * i == N) {
                num++;
            }
        }
    }

    printf("%d", num);

    return 0;
}