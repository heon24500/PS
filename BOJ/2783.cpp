#include <iostream>
using namespace std;

int main() {
    double X, Y;
    int N;
    cin >> X >> Y;

    double min = X / Y;

    cin >> N;
    for (int i = 0; i < N; i++) {
        double xi, yi;
        cin >> xi >> yi;

        double pay = xi / yi;
        if (min > pay) min = pay;
    }

    cout << fixed;
    cout.precision(2);
    cout << min * 1000;

    return 0;
}