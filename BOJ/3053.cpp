#include <iostream>
using namespace std;

int main() {
    double u_ret, t_ret, pi = 3.14159265358979;
    int R;
    cin >> R;

    u_ret = R * R * pi;
    t_ret = R * R * 2;

    cout << fixed;
    cout.precision(6);
    cout << u_ret << endl << t_ret;

    return 0;
}