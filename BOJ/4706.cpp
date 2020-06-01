#include <iostream>
#include <math.h>
using namespace std;

int main() {
    while (true) {
        double ta, tb, speed;
        cin >> ta >> tb;

        if (ta == 0 && tb == 0) break;

        speed = sqrt(1 - (tb * tb) / (ta * ta));

        cout << fixed;
        cout.precision(3);
        cout << speed << endl;
    }

    return 0;
}