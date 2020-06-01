#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int T, isTrack[7] = { 1, 0, 0, 1, 0, 0, 1 };
    double A[7] = { 9.23076, 1.84523, 56.0211, 4.99087, 0.188807, 15.9803, 0.11193 };
    double B[7] = { 26.7, 75, 1.5, 42.5, 210, 3.8, 254 };
    double C[7] = { 1.835, 1.348, 1.05, 1.81, 1.41, 1.04, 1.88 };
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int P[7], total = 0;

        for (int j = 0; j < 7; j++) {
            scanf("%d", &P[j]);
            if (isTrack[j]) total += (A[j] * pow(B[j] - P[j], C[j]));
            else total += (A[j] * pow(P[j] - B[j], C[j]));
        }

        printf("%d\n", total);
    }

    return 0;
}