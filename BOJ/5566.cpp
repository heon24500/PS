#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> X;
    int N, M, cnt = 0, locate = 1;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        X.push_back(x);
    }

    for (int i = 0; i < M; i++) {
        int dice;
        scanf("%d", &dice);

        if (locate >= N) break;

        locate += dice;
        locate += X[locate - 1];
        cnt++;
    }

    printf("%d", cnt);

    return 0;
}