#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int N, W, H, D;
    cin >> N >> W >> H;
    D = sqrt(W * W + H * H);

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num > D) cout << "NE" << endl;
        else cout << "DA" << endl;
    }

    return 0;
}