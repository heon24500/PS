#include <iostream>
using namespace std;

int main() {
    int P;
    scanf("%d", &P);

    for (int i = 0; i < P; i++) {
        int N;
        double D, A, B, F;
        scanf("%d %lf %lf %lf %lf", &N, &D, &A, &B, &F);

        double distance = (D / (A + B)) * F;
        printf("%d %.6lf\n", N, distance);
    }

    return 0;
}