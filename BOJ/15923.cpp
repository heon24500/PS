#include <iostream>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, x[20], y[20], sum = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < N; i++) {
        int x_len, y_len, len;
        if (i != N - 1) {
            x_len = x[i + 1] - x[i];
            y_len = y[i + 1] - y[i];
            len = sqrt(x_len * x_len + y_len * y_len);
        }
        else {
            x_len = x[0] - x[i];
            y_len = y[0] - y[i];
            len = sqrt(x_len * x_len + y_len * y_len);
        }

        sum += len;
    }

    cout << sum;
}