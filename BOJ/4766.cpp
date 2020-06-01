#include <iostream>
using namespace std;

int main() {
    double temp, before_temp;
    cin >> before_temp;

    while (true) {
        cin >> temp;

        if (temp == 999) break;

        double diff = temp - before_temp;
        cout << fixed;
        cout.precision(2);
        cout << diff << endl;

        before_temp = temp;
    }

    return 0;
}